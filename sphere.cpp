#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    // variables for Discriminate 
    double descriminate, t_1, t_2, a, b, c; 
    vec3 u, w;
    
    //Find the descriminate then check for interesection
    u = ray.direction;
    w = ray.endpoint - center;
    a = u.magnitude_squared(); // A = dot product of vector a == |a|^2
    b = 2 * dot(u, w);
    c = w.magnitude_squared() - (radius * radius); // dot(w,w) - Radius^2
    descriminate = (b * b) - (4 * a * c);
    
    // The ray does not intersect. return null hit
    if (descriminate < 0) 
    {
	    return {NULL, -1, part};
    }

    // Find two possible interestions.
    t_1 = (-b + sqrt(descriminate)) / (2 * a);
    t_2 = (-b - sqrt(descriminate)) / (2 * a);
        
    // Find closest interstion.
    if (t_1 < t_2 && t_1 >= small_t) 
    {
        //intersect.dist = t_1;
        //intersect.object = this;
	//intersection.dist = t_1;
	return {this, t_1, part};
    } 
    else if (t_2 <= t_1 && t_2 >= small_t)
    {
        //intersection.dist = t_2;
        //intersection.object = this;
	//intersection.dist = t_2;
	return {this, t_2, part};
    }
    else 
    {
	return {NULL, -1, part};
    }
    
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; //normal = point - center; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
