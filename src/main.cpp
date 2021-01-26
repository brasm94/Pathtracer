//inspired by http://www.kevinbeason.com/smallpt/
#include <math.h> 
#include "Vec.h"
#include "Test.h"
#include "Ray.h"
#include "Sphere.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <limits>


//Globals Bad

Vec CastRay(Ray ray, std::vector<Sphere> &spheres){

    double distance = 1e20, lim = 1e20; 

    for(unsigned int i = 0; i < spheres.size(); i++){
        double temp = spheres[i].Intersect(ray);
        if(temp != 0 && temp < distance)
            distance = temp;
    }
    if(distance == lim){
        return Vec(0,0,0);
    }
    Vec temp = ray.direction * distance;
    double dis = 1 - (temp.Magnitude() - 4) / 1.0;
    int scaled = int(dis * 255);
    // printf("%d %f\n",scaled,dis);

    return Vec(scaled,scaled,scaled);
}
void WriteToFile(Vec * buffer, int height, int width, std::string filename)
{
    std::string headers = "P3\n" + std::to_string(height) + " " + std::to_string(width) + "\n" + "255\n";
	std::string data = "";
	for (int row = 0 ;row < height; row++)
	{
		for (int col = 0 ; col < width; col++)
		{
			data += buffer[row * width + col].ToRGB();
		}
		data += "\n";
	}
	std::string total = headers + data;
	std::ofstream myFile;
	myFile.open(filename);
	if(myFile.is_open())
	{
		myFile << total;
	}
	myFile.close();
	return;
}

int main(int argc, char *argv[]){
    int width = 512;
    int height = 512;
    // int sample = 50;
    double fov = M_PI / 4;
    Ray camera = Ray(Vec(0,0,0), Vec(0,0,-1).Norm());
    double image_aspect_ratio = double(width) / double(height);
    double scale = tan(fov / 2);

    //Set Scene
    std::vector<Sphere> spheres;
    spheres.push_back(Sphere(Vec(0.0,0.0,-5.0),1.0));
    //Buffer image
    Vec  buffer[height * width];
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            double Px = (2 * (x + 0.5) / float(width) - 1 ) * scale * image_aspect_ratio;
            double Py = (1 - 2 * (y + 0.5) / float(height) ) * scale;
            // printf("%f %f\n",Px,Py);
            Ray ray = Ray( camera.origin, (Vec(Px,Py,-1) - camera.origin).Norm() );
            buffer[y * width + x] = CastRay(ray, spheres);
        }
    }

    WriteToFile(buffer, height, width,"test.ppm");
    return 0;
};
