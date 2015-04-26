
#include <string>
#include <string.h> /* for memcpy */

namespace UniplugBL {

/**************** Declaratinons ****************/

// ADD DECLARATIONS...

/**************** Object ****************/

/**
 * Object datablock defining an object in a scene
 */
	class Object {
	public:
		Object() {
			// not implemented
		}

		//inline ID data(void);
		enum type_enum {
			type_MESH = 1,
			type_CURVE = 2,
			type_SURFACE = 3,
			type_META = 5,
			type_FONT = 4,
			type_ARMATURE = 25,
			type_LATTICE = 22,
			type_EMPTY = 0,
			type_CAMERA = 11,
			type_LAMP = 10,
			type_SPEAKER = 12,
		};
		type_enum type(void){ return type_SPEAKER; }
		void type(type_enum value){};
		enum mode_enum {
			mode_OBJECT = 0,
			mode_EDIT = 1,
			mode_POSE = 64,
			mode_SCULPT = 2,
			mode_VERTEX_PAINT = 4,
			mode_WEIGHT_PAINT = 8,
			mode_TEXTURE_PAINT = 16,
			mode_PARTICLE_EDIT = 32,
		};
		inline mode_enum mode(void){
			return mode_EDIT;
		};
		inline void mode(mode_enum value){};
		inline bool* layers(void) { /* not implemented */return NULL; }
		inline void layers(bool values[20]) { /* not implemented */ }

		inline bool* layers_local_view(void) { /* not implemented */ return NULL; }
		inline void layers_local_view(bool values[8]) { /* not implemented */ }

		inline bool select(void){ return false; };
		inline void select(int value){};
		inline float* bound_box(void) { /* not implemented */ return NULL; }
		inline void bound_box(float values[24]) { /* not implemented */ }


		/**
		 * Cast a ray onto in object space
		 * @param
		 * @param
		 * @param The hit location of this ray cast
		 * @param The face normal at the ray cast hit location
		 * @param The face index, -1 when no intersection is found
		 */
		/*inline void ray_cast(float start[3], float end[3], float *location, float *normal, int *index)
		{
			// not implemented
		}*/

		/**
		 * Find the nearest point on the object
		 * @param
		 * @param
		 * @param The location on the object closest to the point
		 * @param The face normal at the closest point
		 * @param The face index, -1 when no closest point is found
		 */
		inline void closest_point_on_mesh(float point[3], float max_dist, float location[3], float normal[3], int *index)
		{
			// not implemented
		}
	};
	

/**************** Implementation ****************/

}

//#endif /* __RNA_BLENDER_CPP_H__ */

