
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
	Object()
	{
		// not implemented
	}

	/* Getter: Object data */
	//ID data(void) { /* not implemented */ return NULL; }

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
	/* Setter/Getter: Type of Object */
	//type_enum type(void) { /* not implemented */ return NULL; }
	void type(type_enum value) { /* not implemented */ }

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
	/* Setter/Getter: Object interaction mode */
	//mode_enum mode(void) { /* not implemented */ return NULL; }
	void mode(mode_enum value) { /* not implemented */ }

	/* Setter/Getter: Layers the object is on */
	bool* layers(void) { /* not implemented */ return NULL; }
	void layers(bool values[20]) { /* not implemented */ }

	/* Setter/Getter: 3D local view layers the object is on */
	bool* layers_local_view(void) { /* not implemented */ return NULL; }
	void layers_local_view(bool values[8]) { /* not implemented */ }

	/* Object selection state */
	bool select(void) { /* not implemented */ return NULL; }
	void select(int value) { /* not implemented */ }

	/* Setter/Getter: Object's bounding box in object-space coordinates, all values are -1.0 when not available */
	float bound_box(void) { /* not implemented */ return NULL; }
	void bound_box(float values[24]) { /* not implemented */ }

	/* Getter: Parent Object */
	//Object parent(void) { /* not implemented */ return NULL; }

	enum parent_type_enum {
		parent_type_OBJECT = 0,
		parent_type_CURVE = 1,
		parent_type_KEY = 2,
		parent_type_ARMATURE = 4,
		parent_type_LATTICE = 4,
		parent_type_VERTEX = 5,
		parent_type_VERTEX_3 = 6,
		parent_type_BONE = 7,
	};
	/* Setter/Getter: Type of parent relation */
	//parent_type_enum parent_type(void) { /* not implemented */ return NULL; }
	void parent_type(parent_type_enum value) { /* not implemented */ }

	/* Setter/Getter: Indices of vertices in case of a vertex parenting relation */
	int* parent_vertices(void) { /* not implemented */ return NULL; }
	void parent_vertices(int values[3]) { /* not implemented */ }

	/* Setter/Getter: Name of parent bone in case of a bone parenting relation */
	inline std::string parent_bone(void) { /* not implemented */ return NULL; }
	inline void parent_bone(const std::string& value) { /* not implemented */ }

	enum track_axis_enum {
		track_axis_POS_X = 0,
		track_axis_POS_Y = 1,
		track_axis_POS_Z = 2,
		track_axis_NEG_X = 3,
		track_axis_NEG_Y = 4,
		track_axis_NEG_Z = 5,
	};
	/* Setter/Getter: Axis that points in 'forward' direction (applies to DupliFrame when parent 'Follow' is enabled) */
	//track_axis_enum track_axis(void) { /* not implemented */ return NULL; }
	void track_axis(track_axis_enum value) { /* not implemented */ }

	enum up_axis_enum {
		up_axis_X = 0,
		up_axis_Y = 1,
		up_axis_Z = 2,
	};
	/* Setter/Getter: Axis that points in the upward direction (applies to DupliFrame when parent 'Follow' is enabled) */
	//up_axis_enum up_axis(void) { /* not implemented */ return NULL; }
	void up_axis(up_axis_enum value) { /* not implemented */ }

	/* Getter: Library object this proxy object controls */
	//Object proxy(void) { /* not implemented */ return NULL; }

	/* Getter: Library group duplicator object this proxy object controls */
	//Object proxy_group(void) { /* not implemented */ return NULL; }

	//COLLECTION_PROPERTY(DefaultCollectionFunctions, MaterialSlot, Object, material_slots, false, false, false)
	/* Getter: Active material being displayed */
	//Material active_material(void) { /* not implemented */ return NULL; }

	/* Setter/Getter: Index of active material slot */
	int active_material_index(void) { /* not implemented */ return NULL; }
	void active_material_index(int value) { /* not implemented */ }

	/* Setter/Getter: Location of the object */
	float location(void) { /* not implemented */ return NULL; }
	void location(float values[3]) { /* not implemented */ }

	/* Setter/Getter: Rotation in Quaternions */
	float rotation_quaternion(void) { /* not implemented */ return NULL; }
	void rotation_quaternion(float values[4]) { /* not implemented */ }

	/* Setter/Getter: Angle of Rotation for Axis-Angle rotation representation */
	float rotation_axis_angle(void) { /* not implemented */ return NULL; }
	void rotation_axis_angle(float values[4]) { /* not implemented */ }

	/* Setter/Getter: Rotation in Eulers */
	float rotation_euler(void) { /* not implemented */ return NULL; }
	void rotation_euler(float values[3]) { /* not implemented */ }

	enum rotation_mode_enum {
		rotation_mode_QUATERNION = 0,
		rotation_mode_XYZ = 1,
		rotation_mode_XZY = 2,
		rotation_mode_YXZ = 3,
		rotation_mode_YZX = 4,
		rotation_mode_ZXY = 5,
		rotation_mode_ZYX = 6,
		rotation_mode_AXIS_ANGLE = -1,
	};
	/* Setter/Getter:  */
	//rotation_mode_enum rotation_mode(void) { /* not implemented */ return NULL; }
	void rotation_mode(rotation_mode_enum value) { /* not implemented */ }

	/* Setter/Getter: Scaling of the object */
	float scale(void) { /* not implemented */ return NULL; }
	void scale(float values[3]) { /* not implemented */ }

	/* Setter/Getter: Absolute bounding box dimensions of the object */
	float dimensions(void) { /* not implemented */ return NULL; }
	void dimensions(float values[3]) { /* not implemented */ }

	/* Setter/Getter: Extra translation added to the location of the object */
	float delta_location(void) { /* not implemented */ return NULL; }
	void delta_location(float values[3]) { /* not implemented */ }

	/* Setter/Getter: Extra rotation added to the rotation of the object (when using Euler rotations) */
	float delta_rotation_euler(void) { /* not implemented */ return NULL; }
	void delta_rotation_euler(float values[3]) { /* not implemented */ }

	/* Setter/Getter: Extra rotation added to the rotation of the object (when using Quaternion rotations) */
	float delta_rotation_quaternion(void) { /* not implemented */ return NULL; }
	void delta_rotation_quaternion(float values[4]) { /* not implemented */ }

	/* Setter/Getter: Extra scaling added to the scale of the object */
	float delta_scale(void) { /* not implemented */ return NULL; }
	void delta_scale(float values[3]) { /* not implemented */ }

	/* Setter/Getter: Lock editing of location in the interface */
	bool* lock_location(void) { /* not implemented */ return NULL; }
	void lock_location(bool values[3]) { /* not implemented */ }

	/* Setter/Getter: Lock editing of rotation in the interface */
	bool* lock_rotation(void) { /* not implemented */ return NULL; }
	void lock_rotation(bool values[3]) { /* not implemented */ }

	/* Lock editing of 'angle' component of four-component rotations in the interface */
	bool lock_rotation_w(void) { /* not implemented */ return NULL; }
	void lock_rotation_w(int value) { /* not implemented */ }

	/* Lock editing of four component rotations by components (instead of as Eulers) */
	bool lock_rotations_4d(void) { /* not implemented */ return NULL; }
	void lock_rotations_4d(int value) { /* not implemented */ }

	/* Setter/Getter: Lock editing of scale in the interface */
	bool* lock_scale(void) { /* not implemented */ return NULL; }
	void lock_scale(bool values[3]) { /* not implemented */ }

	/* Setter/Getter: Worldspace transformation matrix */
	float matrix_world(void) { /* not implemented */ return NULL; }
	void matrix_world(float values[16]) { /* not implemented */ }

	/* Setter/Getter: Parent relative transformation matrix - WARNING: Only takes into account 'Object' parenting, so e.g. in case of bone parenting you get a matrix relative to the Armature object, not to the actual parent bone */
	float matrix_local(void) { /* not implemented */ return NULL; }
	void matrix_local(float values[16]) { /* not implemented */ }

	/* Setter/Getter: Matrix access to location, rotation and scale (including deltas), before constraints and parenting are applied */
	float matrix_basis(void) { /* not implemented */ return NULL; }
	void matrix_basis(float values[16]) { /* not implemented */ }

	/* Setter/Getter: Inverse of object's parent matrix at time of parenting */
	float matrix_parent_inverse(void) { /* not implemented */ return NULL; }
	void matrix_parent_inverse(float values[16]) { /* not implemented */ }

	//COLLECTION_PROPERTY(ObjectModifiers, Modifier, Object, modifiers, false, false, false)
	//COLLECTION_PROPERTY(ObjectConstraints, Constraint, Object, constraints, false, false, false)
	/* Getter: Game engine related settings for the object */
	//GameObjectSettings game(void) { /* not implemented */ return NULL; }

	//COLLECTION_PROPERTY(VertexGroups, VertexGroup, Object, vertex_groups, false, false, false)
	enum empty_draw_type_enum {
		empty_draw_type_PLAIN_AXES = 2,
		empty_draw_type_ARROWS = 1,
		empty_draw_type_SINGLE_ARROW = 4,
		empty_draw_type_CIRCLE = 3,
		empty_draw_type_CUBE = 5,
		empty_draw_type_SPHERE = 6,
		empty_draw_type_CONE = 7,
		empty_draw_type_IMAGE = 8,
	};
	/* Setter/Getter: Viewport display style for empties */
	//empty_draw_type_enum empty_draw_type(void) { /* not implemented */ return NULL; }
	void empty_draw_type(empty_draw_type_enum value) { /* not implemented */ }

	/* Setter/Getter: Size of display for empties in the viewport */
	float empty_draw_size(void) { /* not implemented */ return NULL; }
	void empty_draw_size(float value) { /* not implemented */ }

	/* Setter/Getter: Origin offset distance */
	float empty_image_offset(void) { /* not implemented */ return NULL; }
	void empty_image_offset(float values[2]) { /* not implemented */ }

	/* Getter: Parameters defining which layer, pass and frame of the image is displayed */
	//ImageUser image_user(void) { /* not implemented */ return NULL; }

	/* Setter/Getter: Index number for the IndexOB render pass */
	int pass_index(void) { /* not implemented */ return NULL; }
	void pass_index(int value) { /* not implemented */ }

	/* Setter/Getter: Object color and alpha, used when faces have the ObColor mode enabled */
	float color(void) { /* not implemented */ return NULL; }
	void color(float values[4]) { /* not implemented */ }

	/* Getter: Settings for using the object as a field in physics simulation */
	//FieldSettings field(void) { /* not implemented */ return NULL; }

	/* Getter: Settings for using the object as a collider in physics simulation */
	//CollisionSettings collision(void) { /* not implemented */ return NULL; }

	/* Getter: Settings for soft body simulation */
	//SoftBodySettings soft_body(void) { /* not implemented */ return NULL; }

	//COLLECTION_PROPERTY(ParticleSystems, ParticleSystem, Object, particle_systems, false, false, false)
	/* Getter: Settings for rigid body simulation */
	//RigidBodyObject rigid_body(void) { /* not implemented */ return NULL; }

	/* Getter: Constraint constraining rigid bodies */
	//RigidBodyConstraint rigid_body_constraint(void) { /* not implemented */ return NULL; }

	/* Restrict visibility in the viewport */
	bool hide(void) { /* not implemented */ return NULL; }
	void hide(int value) { /* not implemented */ }

	/* Restrict selection in the viewport */
	bool hide_select(void) { /* not implemented */ return NULL; }
	void hide_select(int value) { /* not implemented */ }

	/* Restrict renderability */
	bool hide_render(void) { /* not implemented */ return NULL; }
	void hide_render(int value) { /* not implemented */ }

	/* Getter: Animation data for this datablock */
	//AnimData animation_data(void) { /* not implemented */ return NULL; }

	/* Getter: Animation data for this datablock */
	//AnimViz animation_visualization(void) { /* not implemented */ return NULL; }

	/* Getter: Motion Path for this element */
	//MotionPath motion_path(void) { /* not implemented */ return NULL; }

	/* Create a delay in the parent relationship (beware: this isn't renderfarm safe and may be invalid after jumping around the timeline) */
	bool use_slow_parent(void) { /* not implemented */ return NULL; }
	void use_slow_parent(int value) { /* not implemented */ }

	/* Setter/Getter: Delay in the parent relationship */
	float slow_parent_offset(void) { /* not implemented */ return NULL; }
	void slow_parent_offset(float value) { /* not implemented */ }

	/* Refresh this object again on frame changes, dependency graph hack */
	bool use_extra_recalc_object(void) { /* not implemented */ return NULL; }
	void use_extra_recalc_object(int value) { /* not implemented */ }

	/* Refresh this object's data again on frame changes, dependency graph hack */
	bool use_extra_recalc_data(void) { /* not implemented */ return NULL; }
	void use_extra_recalc_data(int value) { /* not implemented */ }

	enum dupli_type_enum {
		dupli_type_NONE = 0,
		dupli_type_FRAMES = 8,
		dupli_type_VERTS = 16,
		dupli_type_FACES = 512,
		dupli_type_GROUP = 256,
	};
	/* Setter/Getter: If not None, object duplication method to use */
	//dupli_type_enum dupli_type(void) { /* not implemented */ return NULL; }
	void dupli_type(dupli_type_enum value) { /* not implemented */ }

	/* Set dupliframes to use the current frame instead of parent curve's evaluation time */
	bool use_dupli_frames_speed(void) { /* not implemented */ return NULL; }
	void use_dupli_frames_speed(int value) { /* not implemented */ }

	/* Rotate dupli according to vertex normal */
	bool use_dupli_vertices_rotation(void) { /* not implemented */ return NULL; }
	void use_dupli_vertices_rotation(int value) { /* not implemented */ }

	/* Scale dupli based on face size */
	bool use_dupli_faces_scale(void) { /* not implemented */ return NULL; }
	void use_dupli_faces_scale(int value) { /* not implemented */ }

	/* Setter/Getter: Scale the DupliFace objects */
	float dupli_faces_scale(void) { /* not implemented */ return NULL; }
	void dupli_faces_scale(float value) { /* not implemented */ }

	/* Getter: Instance an existing group */
	//Group dupli_group(void) { /* not implemented */ return NULL; }

	/* Setter/Getter: Start frame for DupliFrames */
	int dupli_frames_start(void) { /* not implemented */ return NULL; }
	void dupli_frames_start(int value) { /* not implemented */ }

	/* Setter/Getter: End frame for DupliFrames */
	int dupli_frames_end(void) { /* not implemented */ return NULL; }
	void dupli_frames_end(int value) { /* not implemented */ }

	/* Setter/Getter: Number of frames to use between DupOff frames */
	int dupli_frames_on(void) { /* not implemented */ return NULL; }
	void dupli_frames_on(int value) { /* not implemented */ }

	/* Setter/Getter: Recurring frames to exclude from the Dupliframes */
	int dupli_frames_off(void) { /* not implemented */ return NULL; }
	void dupli_frames_off(int value) { /* not implemented */ }

	//COLLECTION_PROPERTY(DefaultCollectionFunctions, DupliObject, Object, dupli_list, false, false, false)
	/*  */
	//bool is_duplicator(void) { /* not implemented */ return NULL; }
	void is_duplicator(int value) { /* not implemented */ }

	enum draw_type_enum {
		draw_type_BOUNDS = 1,
		draw_type_WIRE = 2,
		draw_type_SOLID = 3,
		draw_type_TEXTURED = 5,
	};
	/* Setter/Getter: Maximum draw type to display object with in viewport */
	//draw_type_enum draw_type(void) { /* not implemented */ return NULL; }
	void draw_type(draw_type_enum value) { /* not implemented */ }

	/* Display the object's bounds */
	bool show_bounds(void) { /* not implemented */ return NULL; }
	void show_bounds(int value) { /* not implemented */ }

	enum draw_bounds_type_enum {
		draw_bounds_type_BOX = 0,
		draw_bounds_type_SPHERE = 1,
		draw_bounds_type_CYLINDER = 2,
		draw_bounds_type_CONE = 3,
		draw_bounds_type_CAPSULE = 7,
	};
	/* Setter/Getter: Object boundary display type */
	//draw_bounds_type_enum draw_bounds_type(void) { /* not implemented */ return NULL; }
	void draw_bounds_type(draw_bounds_type_enum value) { /* not implemented */ }

	/* Display the object's name */
	bool show_name(void) { /* not implemented */ return NULL; }
	void show_name(int value) { /* not implemented */ }

	/* Display the object's origin and axes */
	bool show_axis(void) { /* not implemented */ return NULL; }
	void show_axis(int value) { /* not implemented */ }

	/* Display the object's texture space */
	bool show_texture_space(void) { /* not implemented */ return NULL; }
	void show_texture_space(int value) { /* not implemented */ }

	/* Add the object's wireframe over solid drawing */
	bool show_wire(void) { /* not implemented */ return NULL; }
	void show_wire(int value) { /* not implemented */ }

	/* Display all edges for mesh objects */
	bool show_all_edges(void) { /* not implemented */ return NULL; }
	void show_all_edges(int value) { /* not implemented */ }

	/* Display material transparency in the object (unsupported for duplicator drawing) */
	bool show_transparent(void) { /* not implemented */ return NULL; }
	void show_transparent(int value) { /* not implemented */ }

	/* Make the object draw in front of others (unsupported for duplicator drawing) */
	bool show_x_ray(void) { /* not implemented */ return NULL; }
	void show_x_ray(int value) { /* not implemented */ }

	/* Getter: Grease Pencil datablock */
	//GreasePencil grease_pencil(void) { /* not implemented */ return NULL; }

	/* Getter: Action used as a pose library for armatures */
	//Action pose_library(void) { /* not implemented */ return NULL; }

	/* Getter: Current pose for armatures */
	//Pose pose(void) { /* not implemented */ return NULL; }

	/* Always show the current Shape for this Object */
	bool show_only_shape_key(void) { /* not implemented */ return NULL; }
	void show_only_shape_key(int value) { /* not implemented */ }

	/* Apply shape keys in edit mode (for Meshes only) */
	bool use_shape_key_edit_mode(void) { /* not implemented */ return NULL; }
	void use_shape_key_edit_mode(int value) { /* not implemented */ }

	/* Getter: Current shape key */
	//ShapeKey active_shape_key(void) { /* not implemented */ return NULL; }

	/* Setter/Getter: Current shape key index */
	int active_shape_key_index(void) { /* not implemented */ return NULL; }
	void active_shape_key_index(int value) { /* not implemented */ }

	/* (null) */
	bool use_dynamic_topology_sculpting(void) { /* not implemented */ return NULL; }
	void use_dynamic_topology_sculpting(int value) { /* not implemented */ }

	//COLLECTION_PROPERTY(DefaultCollectionFunctions, LodLevel, Object, lod_levels, false, false, false)

	/**
	 * Convert (transform) the given matrix from one space to another
	 * @param Bone to use to define spaces (may be None, in which case only the two 'WORLD' and 'LOCAL' spaces are usable)
	 * @param The matrix to transform
	 * @param The transformed matrix
	 * @param The space in which 'matrix' is currently
	 * @param The space to which you want to transform 'matrix'
	 */
	/*inline void convert_space(PoseBone pose_bone, float matrix[16], float matrix_return[16], space_items from_space=WORLD, space_items to_space=WORLD)
	{
		// not implemented
	}*/

	/**
	 * Generate the camera projection matrix of this object (mostly useful for Camera and Lamp types)
	 * @param The camera projection matrix
	 * @param Width of the render area
	 * @param Height of the render area
	 * @param Width scaling factor
	 * @param height scaling factor
	 */
	inline void calc_matrix_camera(float result[16], int x, int y, float scale_x, float scale_y)
	{
		// not implemented
	}

	/**
	 * Compute the coordinate (and scale for ortho cameras) given object should be to 'see' all given coordinates
	 * @param Scene to get render size information from, if available
	 * @param Coordinates to fit in
	 * @param The location to aim to be able to see all given points
	 * @param The ortho scale to aim to be able to see all given points (if relevant)
	 */
	/*inline void camera_fit_coords(Scene scene, int coordinates_len, float *coordinates, float co_return[3], float *scale_return)
	{
		// not implemented
	}*/

	/**
	 * Create a Mesh datablock with modifiers applied
	 * @param Scene within which to evaluate modifiers
	 * @param Apply modifiers
	 * @param Modifier settings to apply
	 * @param Calculate tessellation faces
	 * @param Calculate undeformed vertex coordinates
	 * @return Mesh created from object, remove it if it is only used for export
	 */
	/*inline Mesh to_mesh(Scene scene, bool apply_modifiers, mesh_type_items settings, bool calc_tessface=true, bool calc_undeformed=false)
	{
		// not implemented
	}*/

	/**
	 * Create a list of dupli objects for this object, needs to be freed manually with free_dupli_list to restore the objects real matrix and layers
	 * @param Scene within which to evaluate duplis
	 * @param Generate texture coordinates for rendering
	 */
	/*inline void dupli_list_create(Scene scene, dupli_eval_mode_items settings=VIEWPORT)
	{
		// not implemented
	}*/

	/**
	 * Free the list of dupli objects
	 */
	inline void dupli_list_clear()
	{
		// not implemented
	}

	/**
	 * Find armature influencing this object as a parent or via a modifier
	 * @return Armature object influencing this object or NULL
	 */
	/*inline Object find_armature()
	{
		// not implemented
	}*/

	/**
	 * Add shape key to an object
	 * @param Unique name for the new keyblock
	 * @param Create new shape from existing mix of shapes
	 * @return New shape keyblock
	 */
	/*inline ShapeKey shape_key_add(const string name, bool from_mix=true)
	{
		// not implemented
	}*/

	inline void test(int f[3], int *i)
	{}

	/**
	 * Cast a ray onto in object space
	 * @param 
	 * @param 
	 * @param The hit location of this ray cast
	 * @param The face normal at the ray cast hit location
	 * @param The face index, -1 when no intersection is found
	 */
	inline void ray_cast(float start[3], float end[3], float location[3], float normal[3], int *index)
	{
		// not implemented
	}

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

	/**
	 * Determine if object is visible in a given scene
	 * @param 
	 * @return Object visibility
	 */
	/*inline bool is_visible(Scene scene)
	{
		// not implemented
	}*/

	/**
	 * Determine if this object is modified from the base mesh data
	 * @param 
	 * @param Modifier settings to apply
	 * @return Object visibility
	 */
	/*inline bool is_modified(Scene scene, mesh_type_items settings)
	{
		// not implemented
	}*/

	/**
	 * Determine if this object is modified by a deformation from the base mesh data
	 * @param 
	 * @param Modifier settings to apply
	 * @return Object visibility
	 */
	/*inline bool is_deform_modified(Scene scene, mesh_type_items settings)
	{
		// not implemented
	}*/

	/**
	 * Returns a string for derived mesh data
	 * @param Modifier settings to apply
	 * @param 
	 */
	/*inline void dm_info(mesh_dm_info_items type, string result)
	{
		// not implemented
	}*/

	/**
	 * Load the objects edit-mode data intp the object data
	 * @return Success
	 */
	inline bool update_from_editmode()
	{
		// not implemented
		return NULL;
	}

	/**
	 * Release memory used by caches associated with this object. Intended to be used by render engines only
	 */
	inline void cache_release()
	{
		// not implemented
	}

};


/**************** Implementation ****************/

}

//#endif /* __RNA_BLENDER_CPP_H__ */

