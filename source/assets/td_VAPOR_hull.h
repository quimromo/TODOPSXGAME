#ifndef _TD_VAPOR_HULL_MESH_
#define _TD_VAPOR_HULL_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured td_VAPOR_hull_Vertices[] = {
    { -9, 531, -413, 0, 20, 8 },
    { 2, 531, -414, 0, 20, 8 },
    { -4, 531, -424, 0, 20, 8 },
    { -69, 163, 186, 0, 23, 18 },
    { 73, 41, 186, 0, 26, 21 },
    { 69, 165, 186, 0, 26, 18 },
    { -73, 41, 186, 0, 23, 21 },
    { 69, 165, 186, 0, 20, 28 },
    { 76, 44, -69, 0, 27, 31 },
    { 72, 167, -69, 0, 27, 28 },
    { 73, 41, 186, 0, 20, 31 },
    { -72, 165, -69, 0, 23, 24 },
    { 72, 167, -69, 0, 26, 24 },
    { 76, 44, -69, 0, 27, 21 },
    { -76, 44, -69, 0, 23, 21 },
    { -69, 163, 186, 0, 27, 24 },
    { -72, 165, -69, 0, 20, 24 },
    { -76, 44, -69, 0, 20, 28 },
    { -73, 41, 186, 0, 27, 28 },
    { 122, 177, 338, 0, 23, 9 },
    { -122, 177, 338, 0, 23, 2 },
    { -120, 168, 331, 0, 22, 2 },
    { 120, 168, 331, 0, 22, 9 },
    { 122, 177, 338, 0, 28, 11 },
    { 123, 168, -436, 0, 28, 31 },
    { 125, 177, -443, 0, 28, 31 },
    { 120, 168, 331, 0, 28, 11 },
    { -125, 177, -443, 0, 27, 18 },
    { 125, 177, -443, 0, 27, 24 },
    { 123, 168, -436, 0, 28, 24 },
    { -123, 168, -436, 0, 28, 18 },
    { -123, 168, -436, 0, 28, 11 },
    { -122, 177, 338, 0, 28, 31 },
    { -125, 177, -443, 0, 28, 11 },
    { -120, 168, 331, 0, 28, 31 },
    { 111, 310, -431, 0, 20, 22 },
    { -111, 310, -431, 0, 14, 22 },
    { -121, 310, -91, 0, 14, 31 },
    { 121, 310, -91, 0, 20, 31 },
    { 61, 306, -109, 0, 22, 19 },
    { -61, 306, -109, 0, 19, 19 },
    { -62, 177, -109, 0, 19, 22 },
    { 62, 177, -109, 0, 22, 22 },
    { 61, 306, -109, 0, 14, 15 },
    { 57, 177, -302, 0, 19, 19 },
    { 56, 306, -302, 0, 19, 15 },
    { 62, 177, -109, 0, 14, 19 },
    { -56, 306, -302, 0, 19, 19 },
    { 56, 306, -302, 0, 22, 19 },
    { 57, 177, -302, 0, 22, 15 },
    { -57, 177, -302, 0, 19, 15 },
    { -61, 306, -109, 0, 19, 19 },
    { -56, 306, -302, 0, 14, 19 },
    { -57, 177, -302, 0, 14, 22 },
    { -62, 177, -109, 0, 19, 22 },
    { 121, 310, -91, 0, 27, 19 },
    { -121, 310, -91, 0, 27, 12 },
    { -118, 306, -95, 0, 27, 12 },
    { 118, 306, -95, 0, 27, 19 },
    { 121, 310, -91, 0, 29, 1 },
    { 109, 306, -427, 0, 28, 10 },
    { 111, 310, -431, 0, 28, 10 },
    { 118, 306, -95, 0, 28, 1 },
    { -111, 310, -431, 0, 28, 4 },
    { 111, 310, -431, 0, 28, 10 },
    { 109, 306, -427, 0, 28, 10 },
    { -109, 306, -427, 0, 28, 4 },
    { -121, 310, -91, 0, 28, 10 },
    { -111, 310, -431, 0, 28, 1 },
    { -109, 306, -427, 0, 28, 1 },
    { -118, 306, -95, 0, 28, 10 },
    { -101, 213, 307, 0, 20, 8 },
    { -97, 225, -415, 0, 20, 7 },
    { -100, 225, 307, 0, 20, 8 },
    { -95, 237, -415, 0, 20, 7 },
    { 97, 225, 307, 0, 20, 7 },
    { 97, 226, -418, 0, 20, 8 },
    { 99, 213, 307, 0, 20, 7 },
    { 95, 238, -418, 0, 20, 8 },
    { -107, 220, 305, 0, 20, 7 },
    { -107, 29, 305, 0, 20, 7 },
    { -110, 220, 317, 0, 21, 7 },
    { -110, 29, 317, 0, 21, 7 },
    { 104, 220, 305, 0, 20, 7 },
    { 104, 29, 305, 0, 20, 7 },
    { 95, 220, 313, 0, 20, 7 },
    { 95, 29, 313, 0, 20, 7 },
    { 97, 225, 62, 0, 20, 7 },
    { 97, 30, 62, 0, 20, 7 },
    { 97, 225, 74, 0, 20, 7 },
    { 97, 30, 74, 0, 20, 7 },
    { 98, 308, -117, 0, 20, 7 },
    { 98, 29, -104, 0, 20, 7 },
    { 98, 308, -104, 0, 20, 7 },
    { 98, 29, -117, 0, 20, 7 },
    { -101, 308, -105, 0, 20, 7 },
    { -102, 29, -117, 0, 19, 7 },
    { -102, 308, -117, 0, 20, 7 },
    { -101, 29, -105, 0, 19, 7 },
    { -110, 225, 66, 0, 20, 7 },
    { -102, 29, 75, 0, 20, 8 },
    { -100, 225, 75, 0, 20, 7 },
    { -112, 29, 66, 0, 20, 8 },
    { -116, 308, -266, 0, 20, 7 },
    { -116, 29, -266, 0, 20, 8 },
    { -106, 308, -258, 0, 21, 7 },
    { -106, 29, -258, 0, 21, 8 },
    { 2, 531, -414, 0, 20, 7 },
    { 2, 38, -414, 0, 20, 8 },
    { -4, 531, -424, 0, 20, 7 },
    { -4, 38, -424, 0, 20, 8 },
    { -105, 308, -423, 0, 20, 7 },
    { -105, 38, -423, 0, 20, 7 },
    { -105, 308, -411, 0, 20, 7 },
    { -105, 38, -411, 0, 20, 7 },
    { 103, 308, -411, 0, 21, 7 },
    { 103, 38, -411, 0, 20, 7 },
    { 103, 308, -423, 0, 21, 7 },
    { 103, 38, -423, 0, 20, 7 },
    { 103, 308, -271, 0, 20, 7 },
    { 103, 29, -271, 0, 20, 7 },
    { 103, 308, -259, 0, 20, 7 },
    { 103, 29, -259, 0, 20, 7 },
    { 100, 231, -412, 0, 20, 7 },
    { -100, 238, -423, 0, 20, 7 },
    { 101, 235, -423, 0, 20, 7 },
    { -100, 230, -412, 0, 20, 7 },
    { 103, 83, 279, 0, 21, 14 },
    { -103, 26, 279, 0, 22, 9 },
    { -103, 83, 279, 0, 21, 9 },
    { 103, 26, 279, 0, 22, 14 },
    { -69, 83, 354, 0, 15, 10 },
    { 69, 26, 334, 0, 14, 14 },
    { 69, 83, 354, 0, 15, 14 },
    { -69, 26, 334, 0, 14, 10 },
    { 69, 83, 478, 0, 16, 9 },
    { 103, 26, 475, 0, 14, 10 },
    { 103, 83, 478, 0, 16, 10 },
    { 69, 26, 475, 0, 14, 9 },
    { -69, 83, 478, 0, 16, 15 },
    { -103, 83, 478, 0, 16, 14 },
    { -69, 26, 475, 0, 14, 15 },
    { -103, 26, 475, 0, 14, 14 },
    { 103, 26, 475, 0, 22, 12 },
    { 103, 83, 279, 0, 24, 17 },
    { 103, 83, 478, 0, 24, 12 },
    { 103, 26, 279, 0, 22, 17 },
    { 69, 26, 334, 0, 16, 12 },
    { 69, 26, 475, 0, 19, 12 },
    { 69, 83, 354, 0, 16, 10 },
    { 69, 83, 478, 0, 19, 10 },
    { 69, 26, 475, 0, 20, 7 },
    { 69, 26, 334, 0, 20, 8 },
    { 103, 26, 475, 0, 20, 7 },
    { 103, 26, 279, 0, 20, 8 },
    { -103, 83, 279, 0, 26, 12 },
    { -103, 26, 475, 0, 24, 17 },
    { -103, 83, 478, 0, 26, 17 },
    { -103, 26, 279, 0, 24, 12 },
    { -69, 26, 475, 0, 19, 12 },
    { -69, 83, 354, 0, 16, 13 },
    { -69, 83, 478, 0, 19, 13 },
    { -69, 26, 334, 0, 16, 12 },
    { -103, 26, 475, 0, 20, 7 },
    { -69, 26, 334, 0, 20, 8 },
    { -69, 26, 475, 0, 20, 7 },
    { -103, 26, 279, 0, 20, 8 },
    { -100, 225, 307, 0, 20, 7 },
    { 108, 220, 319, 0, 20, 7 },
    { 97, 225, 307, 0, 20, 7 },
    { -111, 220, 319, 0, 20, 7 },
    { -100, 225, 307, 0, 20, 7 },
    { 97, 225, 307, 0, 20, 7 },
    { 99, 213, 307, 0, 20, 7 },
    { -101, 213, 307, 0, 20, 7 },
    { 108, 220, 319, 0, 20, 7 },
    { -111, 220, 319, 0, 20, 7 },
    { -101, 213, 307, 0, 20, 7 },
    { 99, 213, 307, 0, 20, 7 },
    { 0, 65, -653, 0, 3, 5 },
    { -75, 55, -557, 0, 1, 8 },
    { 75, 55, -557, 0, 5, 8 },
    { -109, 49, -455, 0, 0, 11 },
    { 109, 49, -455, 0, 6, 11 },
    { 123, 44, -325, 0, 6, 14 },
    { -123, 44, -325, 0, 0, 14 },
    { -76, 44, -69, 0, 1, 21 },
    { -124, 41, -72, 0, 0, 21 },
    { 76, 44, -69, 0, 5, 21 },
    { -73, 41, 186, 0, 1, 27 },
    { 125, 41, -72, 0, 6, 21 },
    { -118, 41, 335, 0, 0, 31 },
    { 73, 41, 186, 0, 5, 27 },
    { 118, 41, 335, 0, 6, 31 },
    { -86, -37, 335, 0, 5, 7 },
    { 0, -78, 335, 0, 7, 8 },
    { 86, -37, 335, 0, 9, 7 },
    { -118, 41, 335, 0, 4, 5 },
    { 118, 41, 335, 0, 10, 5 },
    { -110, 220, 317, 0, 20, 7 },
    { -110, 29, 317, 0, 20, 8 },
    { -98, 220, 314, 0, 20, 7 },
    { -98, 29, 314, 0, 20, 8 },
    { -107, 220, 305, 0, 20, 7 },
    { -107, 29, 305, 0, 20, 8 },
    { 95, 220, 313, 0, 20, 7 },
    { 95, 29, 313, 0, 20, 8 },
    { 106, 220, 317, 0, 20, 7 },
    { 106, 29, 317, 0, 20, 8 },
    { 104, 220, 305, 0, 20, 7 },
    { 104, 29, 305, 0, 20, 8 },
    { 97, 225, 74, 0, 20, 7 },
    { 97, 30, 74, 0, 20, 7 },
    { 108, 225, 68, 0, 20, 7 },
    { 108, 30, 68, 0, 20, 7 },
    { 97, 225, 62, 0, 20, 7 },
    { 97, 30, 62, 0, 20, 7 },
    { 98, 308, -104, 0, 20, 7 },
    { 98, 29, -104, 0, 20, 7 },
    { 108, 308, -110, 0, 20, 7 },
    { 108, 29, -110, 0, 20, 7 },
    { 98, 308, -117, 0, 20, 7 },
    { 98, 29, -117, 0, 20, 7 },
    { -102, 308, -117, 0, 20, 7 },
    { -102, 29, -117, 0, 20, 7 },
    { -112, 308, -110, 0, 20, 7 },
    { -112, 29, -110, 0, 20, 7 },
    { -101, 308, -105, 0, 20, 7 },
    { -101, 29, -105, 0, 20, 7 },
    { -106, 308, -258, 0, 20, 7 },
    { -106, 29, -258, 0, 20, 7 },
    { -105, 308, -270, 0, 20, 7 },
    { -105, 29, -270, 0, 20, 7 },
    { -116, 308, -266, 0, 20, 7 },
    { -116, 29, -266, 0, 20, 7 },
    { 103, 308, -259, 0, 20, 7 },
    { 103, 29, -259, 0, 20, 7 },
    { 114, 308, -265, 0, 20, 7 },
    { 114, 29, -265, 0, 20, 7 },
    { 103, 308, -271, 0, 20, 7 },
    { 103, 29, -271, 0, 20, 7 },
    { -27, 44, -70, 0, 24, 12 },
    { -16, 391, -95, 0, 23, 1 },
    { -18, 44, -97, 0, 23, 12 },
    { -24, 391, -71, 0, 24, 1 },
    { -4, 44, -53, 0, 25, 12 },
    { -4, 391, -56, 0, 25, 1 },
    { 16, 391, -71, 0, 26, 1 },
    { 19, 44, -70, 0, 26, 12 },
    { 8, 391, -95, 0, 26, 1 },
    { 10, 44, -97, 0, 27, 12 },
    { -18, 44, -97, 0, 27, 12 },
    { -16, 391, -95, 0, 27, 1 },
    { -69, 83, 354, 0, 19, 10 },
    { -103, 83, 478, 0, 16, 9 },
    { -69, 83, 478, 0, 16, 10 },
    { -103, 83, 279, 0, 21, 9 },
    { 69, 83, 354, 0, 19, 13 },
    { 103, 83, 279, 0, 21, 14 },
    { 103, 83, 478, 0, 16, 14 },
    { 69, 83, 478, 0, 16, 13 },
    { -101, 213, 307, 0, 20, 7 },
    { -107, 232, -415, 0, 20, 8 },
    { -97, 225, -415, 0, 20, 8 },
    { -111, 220, 319, 0, 20, 7 },
    { -100, 225, 307, 0, 20, 7 },
    { -95, 237, -415, 0, 20, 8 },
    { 107, 234, -418, 0, 20, 7 },
    { 99, 213, 307, 0, 20, 8 },
    { 97, 226, -418, 0, 20, 7 },
    { 108, 220, 319, 0, 20, 8 },
    { 97, 225, 307, 0, 20, 8 },
    { 95, 238, -418, 0, 20, 7 },
    { -110, 225, 66, 0, 20, 7 },
    { -101, 29, 63, 0, 20, 7 },
    { -112, 29, 66, 0, 20, 7 },
    { -99, 225, 63, 0, 20, 7 },
    { -100, 225, 75, 0, 20, 7 },
    { -102, 29, 75, 0, 20, 7 },
    { -4, 531, -424, 0, 20, 7 },
    { -4, 38, -424, 0, 20, 8 },
    { -9, 531, -413, 0, 20, 7 },
    { -9, 38, -413, 0, 20, 8 },
    { -105, 308, -423, 0, 21, 7 },
    { -95, 38, -417, 0, 20, 7 },
    { -105, 38, -423, 0, 20, 7 },
    { -95, 308, -417, 0, 21, 7 },
    { -105, 308, -411, 0, 21, 7 },
    { -105, 38, -411, 0, 20, 7 },
    { 103, 308, -423, 0, 20, 7 },
    { 103, 38, -423, 0, 20, 7 },
    { 93, 308, -417, 0, 20, 7 },
    { 93, 38, -417, 0, 20, 7 },
    { 103, 38, -411, 0, 20, 7 },
    { 103, 308, -411, 0, 20, 7 },
    { 100, 243, -412, 0, 20, 7 },
    { -100, 230, -412, 0, 20, 7 },
    { 100, 231, -412, 0, 20, 7 },
    { -100, 242, -412, 0, 20, 7 },
    { -100, 238, -423, 0, 20, 7 },
    { 101, 235, -423, 0, 20, 7 },
    { 0, 65, -653, 0, 22, 2 },
    { 75, 55, -557, 0, 20, 1 },
    { 0, -7, -617, 0, 21, 3 },
    { 54, -16, -557, 0, 19, 3 },
    { 0, -70, -557, 0, 20, 5 },
    { 109, 49, -455, 0, 17, 1 },
    { 0, -82, -455, 0, 17, 5 },
    { 80, -23, -455, 0, 17, 3 },
    { 123, 44, -325, 0, 14, 1 },
    { 0, -90, -325, 0, 14, 5 },
    { 90, -28, -325, 0, 14, 3 },
    { 125, 41, -72, 0, 9, 1 },
    { 0, -90, -72, 0, 9, 5 },
    { 91, -32, -72, 0, 9, 3 },
    { 118, 41, 335, 0, 0, 1 },
    { 86, -37, 335, 0, 0, 3 },
    { 0, -78, 335, 0, 0, 5 },
    { 0, -7, -617, 0, 21, 3 },
    { -75, 55, -557, 0, 20, 1 },
    { 0, 65, -653, 0, 22, 2 },
    { -54, -16, -557, 0, 19, 3 },
    { 0, -70, -557, 0, 20, 5 },
    { -109, 49, -455, 0, 17, 1 },
    { 0, -82, -455, 0, 17, 5 },
    { -80, -23, -455, 0, 17, 3 },
    { -123, 44, -325, 0, 14, 1 },
    { 0, -90, -325, 0, 14, 5 },
    { -90, -28, -325, 0, 14, 3 },
    { -124, 41, -72, 0, 9, 1 },
    { 0, -90, -72, 0, 9, 5 },
    { -91, -32, -72, 0, 9, 3 },
    { -118, 41, 335, 0, 0, 1 },
    { -86, -37, 335, 0, 0, 3 },
    { 0, -78, 335, 0, 0, 5 },
    { 8, 391, -95, 0, 20, 7 },
    { -16, 391, -95, 0, 20, 7 },
    { -3, 369, -78, 0, 20, 7 },
    { 16, 391, -71, 0, 20, 7 },
    { -4, 391, -56, 0, 20, 7 },
    { -24, 391, -71, 0, 20, 7 },
    { -16, 391, -95, 0, 20, 7 },
    { 69, 165, 186, 0, 20, 7 },
    { -120, 168, 331, 0, 19, 7 },
    { -69, 163, 186, 0, 20, 7 },
    { -72, 165, -69, 0, 20, 7 },
    { 120, 168, 331, 0, 20, 7 },
    { -123, 168, -436, 0, 19, 8 },
    { 72, 167, -69, 0, 20, 7 },
    { 123, 168, -436, 0, 20, 8 },
    { 125, 177, -443, 0, 13, 11 },
    { -57, 177, -302, 0, 9, 14 },
    { 57, 177, -302, 0, 12, 14 },
    { 62, 177, -109, 0, 12, 19 },
    { -125, 177, -443, 0, 7, 11 },
    { 122, 177, 338, 0, 13, 31 },
    { -62, 177, -109, 0, 8, 19 },
    { -122, 177, 338, 0, 7, 31 },
    { 118, 306, -95, 0, 20, 7 },
    { -61, 306, -109, 0, 20, 7 },
    { 61, 306, -109, 0, 20, 7 },
    { 56, 306, -302, 0, 20, 7 },
    { -118, 306, -95, 0, 20, 7 },
    { 109, 306, -427, 0, 20, 8 },
    { -56, 306, -302, 0, 20, 7 },
    { -109, 306, -427, 0, 20, 8 }
};
static u_short td_VAPOR_hull_Indices[] = {
    0, 2, 1, 3, 5, 4, 4, 6, 3, 7, 9, 8, 8, 10, 7, 11, 13, 12, 11, 14, 13, 15, 17, 16, 15, 18, 17, 19, 21, 20, 19, 22, 21, 
    23, 25, 24, 24, 26, 23, 27, 29, 28, 27, 30, 29, 31, 33, 32, 32, 34, 31, 35, 37, 36, 35, 38, 37, 39, 41, 40, 39, 42, 41, 43, 45, 
    44, 44, 46, 43, 47, 49, 48, 47, 50, 49, 51, 53, 52, 51, 54, 53, 55, 57, 56, 55, 58, 57, 59, 61, 60, 60, 62, 59, 63, 65, 64, 63, 
    66, 65, 67, 69, 68, 67, 70, 69, 71, 73, 72, 74, 72, 73, 75, 77, 76, 76, 78, 75, 79, 81, 80, 81, 82, 80, 83, 85, 84, 85, 86, 84, 
    87, 89, 88, 89, 90, 88, 91, 93, 92, 92, 94, 91, 95, 97, 96, 96, 98, 95, 99, 101, 100, 100, 102, 99, 103, 105, 104, 105, 106, 104, 107, 109, 
    108, 109, 110, 108, 111, 113, 112, 113, 114, 112, 115, 117, 116, 117, 118, 116, 119, 121, 120, 121, 122, 120, 123, 125, 124, 124, 126, 123, 127, 129, 128, 128, 
    130, 127, 131, 133, 132, 132, 134, 131, 135, 137, 136, 136, 138, 135, 139, 141, 140, 140, 141, 142, 143, 145, 144, 144, 146, 143, 147, 149, 148, 150, 148, 149, 
    151, 153, 152, 154, 152, 153, 155, 157, 156, 156, 158, 155, 159, 161, 160, 160, 162, 159, 163, 165, 164, 163, 164, 166, 167, 169, 168, 168, 170, 167, 171, 173, 
    172, 171, 174, 173, 175, 177, 176, 175, 178, 177, 179, 181, 180, 182, 180, 181, 182, 181, 183, 182, 183, 184, 184, 185, 182, 186, 185, 184, 185, 186, 187, 184, 
    188, 186, 189, 187, 186, 190, 188, 184, 187, 189, 191, 192, 188, 190, 191, 189, 192, 190, 193, 192, 191, 192, 193, 194, 196, 195, 196, 194, 197, 197, 198, 196, 
    199, 201, 200, 201, 202, 200, 201, 203, 202, 203, 204, 202, 205, 207, 206, 207, 208, 206, 207, 209, 208, 209, 210, 208, 211, 213, 212, 213, 214, 212, 213, 215, 
    214, 215, 216, 214, 217, 219, 218, 219, 220, 218, 219, 221, 220, 221, 222, 220, 223, 225, 224, 225, 226, 224, 225, 227, 226, 227, 228, 226, 229, 231, 230, 231, 
    232, 230, 231, 233, 232, 233, 234, 232, 235, 237, 236, 237, 238, 236, 237, 239, 238, 239, 240, 238, 241, 243, 242, 242, 244, 241, 245, 241, 244, 244, 246, 245, 
    246, 247, 245, 247, 248, 245, 247, 249, 248, 249, 250, 248, 251, 250, 249, 249, 252, 251, 253, 255, 254, 256, 253, 254, 257, 253, 256, 258, 257, 256, 259, 257, 
    258, 257, 259, 260, 261, 263, 262, 264, 261, 262, 265, 264, 262, 262, 266, 265, 267, 269, 268, 268, 270, 267, 267, 270, 271, 272, 267, 271, 273, 275, 274, 276, 
    273, 274, 277, 276, 274, 274, 278, 277, 279, 281, 280, 281, 282, 280, 108, 282, 281, 281, 107, 108, 283, 285, 284, 286, 283, 284, 287, 286, 284, 284, 288, 287, 
    289, 291, 290, 291, 292, 290, 293, 292, 291, 291, 294, 293, 295, 297, 296, 296, 298, 295, 295, 298, 299, 299, 300, 295, 301, 303, 302, 303, 304, 302, 303, 305, 
    304, 306, 302, 304, 304, 305, 307, 304, 308, 306, 307, 308, 304, 309, 306, 308, 308, 307, 310, 308, 311, 309, 310, 311, 308, 312, 309, 311, 311, 310, 313, 311, 
    314, 312, 313, 314, 311, 312, 314, 315, 316, 315, 314, 316, 314, 313, 317, 316, 313, 318, 320, 319, 319, 321, 318, 321, 322, 318, 321, 319, 323, 324, 322, 321, 
    323, 325, 321, 325, 324, 321, 325, 323, 326, 327, 324, 325, 326, 328, 325, 327, 325, 328, 328, 326, 329, 330, 327, 328, 329, 331, 328, 331, 330, 328, 331, 329, 
    332, 332, 333, 331, 333, 330, 331, 330, 333, 334, 335, 337, 336, 338, 337, 335, 339, 337, 338, 340, 337, 339, 341, 337, 340, 342, 344, 343, 343, 344, 345, 343, 
    346, 342, 343, 345, 347, 348, 342, 346, 347, 345, 348, 349, 348, 346, 348, 349, 347, 350, 352, 351, 353, 352, 350, 354, 350, 351, 355, 353, 350, 354, 351, 356, 
    356, 353, 355, 354, 356, 357, 355, 357, 356, 358, 360, 359, 361, 360, 358, 359, 362, 358, 358, 363, 361, 362, 359, 364, 364, 361, 363, 362, 364, 365, 363, 365, 
    364
};
static SDC_Mesh3D td_VAPOR_hull_Mesh = {td_VAPOR_hull_Vertices, td_VAPOR_hull_Indices, NULL, 738, 366, POLIGON_VERTEX_TEXTURED};
#endif