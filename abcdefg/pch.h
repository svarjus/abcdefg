// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#define NOMINMAX

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];

#define PI 3.14159265f
#define M_PI        3.14159265358979323846f // matches value in gcc v2 math.h

#define DEG2RAD(a) (((a) * M_PI) / 180.0F)
#define RAD2DEG(a) (((a) * 180.0f) / M_PI)
#define RAD2SHORT(a) ((a) * (32768.f / (float)M_PI))
#define SHORT2RAD(a) ((a) * ((float)M_PI / 32768.f))
#define SHORT2DEG(a) (((a) / 32768.f) * 180.0f)

#define DotProduct(x,y)			((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define VectorClear( a )              ( ( a )[0] = ( a )[1] = ( a )[2] = 0 )

#define XZY2XYZ(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[2],(b)[2]=(a)[1])
#define XYZ2XZY(a,b)			((b)[0]=(a)[0],(b)[2]=(a)[1],(b)[1]=(a)[2])


#define	PITCH					0		// up / down
#define	YAW						1		// left / right
#define	ROLL					2		// fall over

#define MENU_KEY VK_INSERT

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <psapi.h>
#include <iostream>
#include <utility>
#include <filesystem>
#include <direct.h>
#include <TlHelp32.h>
#include <array>
#include <intrin.h>
#include <functional>
#include <format>
#include <stdio.h>



#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "ImGui/imgui_stdlib.h"

//detours
#include "detours/detours.h"
#pragma comment(lib, "detours.lib")

#include "koukku.h"

#include "evar.h"
#include "evar_config.h"
#include "fs_funcs.h"
#include "dyn_vars.h"

#include "g_objects.h"

#include "u_objects.h"
#include "u_player.hpp"
#include "u_world.hpp"

#include "g_offsets.h"
#include "g_gameobject.h"
#include "g_entrypoint.h"
#include "g_main.h"
#include "g_playercontroller.h"

#include "g_dlc.hpp"
#include "g_secrets.hpp"
#include "g_weapons.hpp"

#include "r_init.h"
#include "r_ui.h"
#include "r_utils.h"
#include "r_pc_editor.h"

#include "mod_vis.hpp"

#include "vector.h"
#include "matrix.h"
#include "math.h"


#endif //PCH_H
