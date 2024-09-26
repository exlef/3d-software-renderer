#pragma once

#include "../include/raylib.h"
#include "../include/raymath.h"
#include "rendering.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
namespace fs = std::filesystem;
using std::cout;
using std::endl;

namespace ssr
{

    class model_loader
    {
    private:
        vector<Vector3> vertices;
        vector<Vector2> uvs;
        vector<Vector3> normals;
        vector<triangle_t> faces;

        vector<string> string_split(const string& str, const string& delimeter)
        {
            vector<string> result;
            size_t previos_index = 0;

            for (size_t i = 0; i < str.length(); i++)
            {
                if (str[i] == delimeter[0])
                {
                    result.push_back(str.substr(previos_index, i - previos_index));
                    previos_index = i + 1;
                }
                // this ads from last delimeter to end of the string.
                if (i == (str.length() - 1))
                {
                    result.push_back(str.substr(previos_index, i - previos_index + 1));
                }
            }
            return result;
        }

        Vector3 read_vec3(const vector<string>& words)
        {
            return (Vector3){std::stof(words[1]), std::stof(words[2]), std::stof(words[3])};
        }

        Vector2 read_vec2(const vector<string>& words)
        {
            return (Vector2){std::stof(words[1]), std::stof(words[2])};
        }

        void read_vertex(tri_indicies& t, const string& data)
        {
            vector<string> splited = string_split(data, "/");
            t.p = std::stoi(splited[0]) - 1;
            t.uv = std::stoi(splited[1]) - 1;
            t.n = std::stoi(splited[2]) - 1;
        }

    public:
        model_t load_obj_data(const string& path)
        {
            string line;
            vector<string> words;

            vector<string> face_serialized_data;

            std::ifstream file;

            file.open(path);
            while (std::getline(file, line))
            {
                words = string_split(line, " ");

                if (!words[0].compare("v"))
                {
                    vertices.push_back(read_vec3(words));
                }

                else if (!words[0].compare("vt"))
                {
                    uvs.push_back(read_vec2(words));
                }

                else if (!words[0].compare("vn"))
                {
                    normals.push_back(read_vec3(words));
                }

                else if (!words[0].compare("f"))
                {
                    for (size_t i = 1; i < words.size(); i++)
                    {
                        face_serialized_data.push_back(words[i]);
                    }
                }
            }
            file.close();

            for (size_t i = 0; i < face_serialized_data.size(); i += 4)
            {
                triangle_t t1;
                triangle_t t2;

                read_vertex(t1.v1, face_serialized_data[i]);     // read first  vertex of first  triangle
                read_vertex(t1.v2, face_serialized_data[i + 1]); // read second vertex of first  triangle
                read_vertex(t1.v3, face_serialized_data[i + 2]); // read third  vertex of first  triangle
                read_vertex(t2.v1, face_serialized_data[i + 2]); // read first  vertex of second triangle
                read_vertex(t2.v2, face_serialized_data[i + 3]); // read second vertex of second triangle
                read_vertex(t2.v3, face_serialized_data[i]);     // read third  vertex of second triangle

                faces.push_back(t1);
                faces.push_back(t2);
            }

            mesh_t model_mesh = {
                .vertices = vertices,
                .uvs = uvs,
                .normals = normals,
                .faces = faces};

            transform_t t = {
                .position = (Vector3){0, 0, 7},
                .rotation = (Vector3){0, DEG2RAD * 0, 0},
                .scale = (Vector3){2, 2, 2}};

            model_t model = {
                .mesh = model_mesh,
                .transform = t};

            return model;
        }
    };
}