/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:55:43 by snagulap          #+#    #+#             */
/*   Updated: 2024/01/14 17:26:48 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"


double degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

t_color	make_color(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

void initialize_camera(t_camera *camera) {
    camera->image_height = (int)(camera->image_width / camera->aspect_ratio);
    camera->image_height = (camera->image_height < 1) ? 1 : camera->image_height;

    camera->center = camera->lookfrom;

    double focal_length = vec3_length((t_vec3){camera->lookfrom.x - camera->lookat.x,
                                            camera->lookfrom.y - camera->lookat.y,
                                            camera->lookfrom.z - camera->lookat.z});

    double theta = degrees_to_radians(camera->vfov);
    double h = tan(theta / 2);
    double viewport_height = 2 * h * focal_length;
    double viewport_width = viewport_height * ((double)camera->image_width / camera->image_height);

    camera->w = vec3_normalize((t_vec3){camera->lookfrom.x - camera->lookat.x,
                                       camera->lookfrom.y - camera->lookat.y,
                                       camera->lookfrom.z - camera->lookat.z});

    camera->u = vec3_normalize(vec3_cross(camera->vup, camera->w));
    camera->v = vec3_cross(camera->w, camera->u);

    t_vec3 viewport_u = (t_vec3){viewport_width * camera->u.e[0], viewport_width * camera->u.e[1], viewport_width * camera->u.e[2]};
    t_vec3 viewport_v = (t_vec3){viewport_height * -camera->v.e[0], viewport_height * -camera->v.e[1], viewport_height * -camera->v.e[2]};

    camera->pixel_delta_u = (t_vec3){viewport_u.e[0] / camera->image_width, viewport_u.e[1] / camera->image_width, viewport_u.e[2] / camera->image_width};
    camera->pixel_delta_v = (t_vec3){viewport_v.e[0] / camera->image_height, viewport_v.e[1] / camera->image_height, viewport_v.e[2] / camera->image_height};

    t_vec3 viewport_upper_left = (t_vec3){camera->center.x - focal_length * camera->w.e[0] - viewport_u.e[0] / 2 - viewport_v.e[0] / 2,
                                       camera->center.y - focal_length * camera->w.e[1] - viewport_u.e[1] / 2 - viewport_v.e[1] / 2,
                                       camera->center.z - focal_length * camera->w.e[2] - viewport_u.e[2] / 2 - viewport_v.e[2] / 2};

    camera->pixel00_loc = (t_point3){viewport_upper_left.e[0] + 0.5 * (camera->pixel_delta_u.e[0] + camera->pixel_delta_v.e[0]),
                                   viewport_upper_left.e[1] + 0.5 * (camera->pixel_delta_u.e[1] + camera->pixel_delta_v.e[1]),
                                   viewport_upper_left.e[2] + 0.5 * (camera->pixel_delta_u.e[2] + camera->pixel_delta_v.e[2])};
}

t_color color_add(t_color a, t_color b) {
    return (t_color){a.red + b.red, a.green + b.green, a.blue + b.blue};
}

t_color color_scalar_multiply(t_color c, double scalar) {
    return (t_color){c.red * scalar, c.green * scalar, c.blue * scalar};
}

t_vec3 unit_vector(t_vec3 v) {
    double length = sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
    return vec3_scalar_multiply(v, 1.0 / length);
}

void add_hittable(t_hittable_list* list, t_hittable* object) {
    list->objects = realloc(list->objects, (list->size + 1) * sizeof(t_hittable));
    list->objects[list->size] = object;  // Dereference the pointer
    list->size++;
}

// Function to clear a hittable list
void clear_hittable_list(t_hittable_list* list) {
    free(list->objects);
    list->objects = NULL;
    list->size = 0;
}

t_hittable_list create_hittable_list(t_hittable* objects, size_t size) {
    t_hittable_list list;
    list.objects = &objects;
    list.size = size;
    return list;
}


int sphere_hit(const t_sphere* s, const t_ray* r, double ray_tmin, double ray_tmax, t_hit_record* rec) {
    t_vec3 oc;
    oc = vec3_sub(r->orig, s->center);
    // double a = vec3_dot(r->dir, r->dir);
    double half_b = vec3_dot(oc, r->dir);
    double c = vec3_dot(oc,oc) - (s->radius * s->radius);

    if(c > 0.0f && half_b > 0.0f)
        return (false);
    double discriminant = half_b * half_b - c;
    if (discriminant < 0)
        return 0;
    // double sqrtd = -half_b -sqrt(discriminant);
    if(discriminant <= ray_tmin || ray_tmax <= discriminant)
        return (0);
    
    rec->t = discriminant;
    rec->p = vec3_add(r->orig,vec3_scalar_multiply(r->dir, discriminant));
    rec->normal = vec3_scalar_multiply(vec3_add(vec3_scalar_multiply(r->dir,discriminant),oc),s->radius);
    // rec->color = 
    // Find the nearest root that lies in the acceptable range.
    // double root = (-half_b - sqrt(discriminant)) / a;
    // if (root <= ray_tmin || ray_tmax <= root) {
    //     root = (-half_b + sqrt(discriminant)) / a;
    //     if (root <= ray_tmin || ray_tmax <= root)
    //         return 0;
    // }

    // rec->t = root;
    // rec->p = vec3_add(vec3_scalar_multiply(r->dir, rec->t),r->orig);
    // // subtract(&rec->p, &s->center, &rec->normal);
    // rec->normal= vec3_normalize(vec3_sub(rect->t,s->center));

    return 1;
}

int hit_hittable_list(const t_hittable_list* list, const t_ray* r, double ray_tmin, double ray_tmax, t_hit_record* rec) {
    t_hit_record temp_rec;
    int hit_anything = 0;
    double closest_so_far = ray_tmax;

    
    for (size_t i = 0; i < list->size; ++i) {
        if (list->objects[i]->type == 0) {
            // Handle sphere hit
            t_sphere* s = &list->objects[i]->data.sphere_data;
            if (sphere_hit(s, r, ray_tmin, closest_so_far, &temp_rec)) {
                hit_anything = 1;
                closest_so_far = temp_rec.t;
                *rec = temp_rec;
            }
        }
    }
    return hit_anything;
}

t_color ray_color(const t_ray* r, const t_hittable_list* world) {
    t_hit_record rec;
    if (hit_hittable_list(world, r, 0, INFINITY, &rec)) {
        t_vec3 outward_normal = vec3_normalize(vec3_sub(rec.normal, (t_vec3){1, 1, 1}));
        return color_scalar_multiply(color_add((t_color){outward_normal.e[0], outward_normal.e[1], outward_normal.e[2]}, (t_color){1, 1, 1}), 0.5);
    }

    t_vec3 unit_direction = unit_vector(r->dir);
    double a = 0.5 * (unit_direction.e[0] + 1.0);
    return color_add(color_scalar_multiply((t_color){1, 1, 1}, 1.0 - a), color_scalar_multiply((t_color){0.5, 0.7, 1.0}, a));
}

// t_ray get_ray(const t_camera *camera, int i, int j) {
//     // Get a randomly-sampled camera ray for the pixel at location i,j, originating from
//     // the camera defocus disk.

//     // Example:
//     t_point3 pixel_center = {0.0, 0.0, 0.0};  // Replace with actual values
//     t_point3 pixel_sample = {0.0, 0.0, 0.0};  // Replace with actual values

//     t_point3 ray_origin = {0.0, 0.0, 0.0};  // Replace with actual values
//     t_vec3 ray_direction = {0.0, 0.0, 0.0};  // Replace with actual values

//     return (t_ray){ray_origin, ray_direction};
// }

int main(int argc, char** argv) 
{

    void	*mlx;
	void	*window;
	// t_camera	cam;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	argc = 0;
	argv = 0;
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (!window)
		return (1);
    // Image
	double aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    int image_width = (double)WINDOW_WIDTH;
    int image_height = (int)(image_width / aspect_ratio);
    // image_height = (image_height < 1) ? 1 : image_height;

    // World
    t_hittable_list world;
    world.objects = NULL;
    world.size = 0;

    // Spheres
    t_vec3 center1 = {0, 0, 20.6};
    t_hittable* sphere1 = malloc(sizeof(t_hittable));
    sphere1->type = 0;  // Assuming 0 represents a sphere
    sphere1->data.sphere_data.center = center1;
    sphere1->data.sphere_data.radius =12.6 /* Set the radius value */;
    sphere1->data.sphere_data.rgb_colors = make_color(10,0,255)/* Set the color values */;
    add_hittable(&world, sphere1);

    
    // t_vec3 center2 = {0, -100.5, -1};
    // t_hittable* sphere2 = malloc(sizeof(t_hittable));
    // sphere2->type = 0;  // Assuming 0 represents a sphere
    // sphere2->data.sphere_data.center = center2;
    // sphere2->data.sphere_data.radius = /* Set the radius value */;
    // sphere2->data.sphere_data.rgb_colors = /* Set the color values */;
    // add_hittable(&world, sphere2);
    // t_vec3 center1 = {0, 0, -1};
    // t_hittable* sphere1 = malloc(sizeof(t_hittable));
    // sphere1->data.sphere_data = &sphere_hit;
    // add_hittable(&world, sphere1);

    // t_vec3 center2 = {0, -100.5, -1};
    // t_hittable* sphere2 = malloc(sizeof(t_hittable));
    // sphere2->data.sphere_data = &sphere_hit;
    // add_hittable(&world, sphere2);

    // Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / image_height);
    t_vec3 camera_center = {-50, 0, 20};

    t_vec3 viewport_u = {viewport_width, 0, 0};
    t_vec3 viewport_v = {0, -viewport_height, 0};

    t_vec3 pixel_delta_u = vec3_scalar_multiply(viewport_u, 1.0 / image_width);
    t_vec3 pixel_delta_v = vec3_scalar_multiply(viewport_v, 1.0 / image_height);

    t_vec3 viewport_upper_left = vec3_add(camera_center, vec3_sub(vec3_sub(vec3_scalar_multiply((t_vec3){0, 0, -focal_length}, 1), viewport_u), viewport_v));
    t_vec3 pixel00_loc = vec3_add(viewport_upper_left, vec3_scalar_multiply(vec3_add(pixel_delta_u, pixel_delta_v), 0.5));

    // Render
    // printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = 0; j < image_height; ++j) {
        // fprintf(stderr, "\rScanlines remaining: %d ", (image_height - j));
        for (int i = 0; i < image_width; ++i) {
            t_vec3 pixel_center = vec3_add(pixel00_loc, vec3_add(vec3_scalar_multiply(pixel_delta_u, i), vec3_scalar_multiply(pixel_delta_v, j)));
            t_vec3 ray_direction = vec3_sub(pixel_center, camera_center);
            t_ray r = make_ray(camera_center, ray_direction);

            t_color pixel_color = ray_color(&r, &world);
            int img = ((int)(255.99 * pixel_color.red)<<16) |((int)(255.99 * pixel_color.green) <<8 ) |((int)(255.99 * pixel_color.blue));
            // printf("%d %d %d\n", (int)(255.99 * pixel_color.red), (int)(255.99 * pixel_color.green), (int)(255.99 * pixel_color.blue));
            mlx_pixel_put(mlx,window,i,j,img);
        }
    }
    mlx_loop(mlx);
	mlx_destroy_window(mlx, window);

    fprintf(stderr, "\rDone.                     \n");

    // Cleanup
    free(sphere1);
    // free(sphere2);

    return 0;
}
