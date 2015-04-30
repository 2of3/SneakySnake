#include "rna_def_types.h"

std::map <std::string, rna_def_ptr> rna_def_map;

std::string get_rna_def_type(std::string str)
{
	std::regex reg("^.*(RNA_def_\\w*).*$");
	str = std::regex_replace(str, reg, "$1");
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	return str;
}

rna_def_ptr get_rna_def_ptr(std::string str)
{
	str = get_rna_def_type(str);

	if (rna_def_map.find(str) != rna_def_map.end())
		return rna_def_map[str];

	return NULL;
}

/* RNA TRANSLATION */
bool rna_def_action()
{
	return false;
}

bool rna_def_action(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_actuator(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_animation(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_animviz(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_armature(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_boid(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_boolean(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], "bool", pmstr[4], pmstr[2]));

	string defval = funcs.back().params.back().defval;
	if (defval == "1") defval = "true";
	if (defval == "0") defval = "false";

	funcs.back().params.back().defval = defval;
	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_boolean_array(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_boolean_layer(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_boolean_layer_member(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_boolean_vector(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_brush(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_camera(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_cloth(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_collection(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_collection_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_color(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_constraint(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_context(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_controller(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_curve(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_dynamic_paint(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_enum(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], pmstr[2], pmstr[5], pmstr[3]));
	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_enum_flag(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_enum_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_fcurve(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], "float", pmstr[6], pmstr[2]));
	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_float_array(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float_color(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float_factor(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float_matrix(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float_percentage(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float_rotation(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_float_vector(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], "float", pmstr[6]));

	string name = funcs.back().params.back().name;
	funcs.back().params.back().name = name + "[" + trim_param_str(pmstr[2]) + "]";
	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_float_vector_xyz(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_fluidsim(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_func_duplicate_pointers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_func_free_pointers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_function(vector<bpy_func> &funcs, string str)
{
	string namestr = get_params(str)[1];

	bpy_func newfunc;
	newfunc.name = trim_param_str(namestr);
	newfunc.error = false;

	fctparam voidparam;
	voidparam.type = "void";
	newfunc.rettype = voidparam;

	funcs.push_back(newfunc);

	return true;
}

bool rna_def_function_flag(vector<bpy_func> &funcs, string str)
{
	return true;
}

bool rna_def_function_output(vector<bpy_func> &funcs, string str)
{
	if (funcs.back().error) return true;

	funcs.back().rettype = funcs.back().params.back();
	funcs.back().params.pop_back();

	return true;
}

bool rna_def_function_return(vector<bpy_func> &funcs, string str)
{
	rna_def_function_output(funcs, str);

	return true;
}

bool rna_def_function_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_function_ui_description(vector<bpy_func> &funcs, string str)
{
	string descstr = get_params(str)[1];
	funcs.back().desc = trim_param_str(descstr);
	
	return true;
}

bool rna_def_gameproperty(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_gpencil(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_group(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_id(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_image(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_int(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], "int", pmstr[6], "\"" + pmstr[2] + "\""));
	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_int_array(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_int_vector(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_key(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_lamp(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_lattice(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_linestyle(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_actions(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_armatures(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_brushes(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_cameras(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_curves(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_fonts(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_gpencil(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_groups(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_images(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_lamps(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_lattices(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_libraries(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_linestyles(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_masks(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_materials(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_meshes(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_metaballs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_movieclips(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_node_groups(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_objects(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_particles(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_scenes(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_screens(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_sounds(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_speakers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_texts(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_textures(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_window_managers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_main_worlds(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_mask(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_material(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_mesh(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_meta(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_modifier(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_movieclip(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_nla(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_nodetree(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_object(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_object_force(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_packedfile(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_particle(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_pointer(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], pmstr[2], pmstr[4]));
	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_pointer_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_pose(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property(vector<bpy_func> &funcs, string str)
{
	if (funcs.size() == 0) return true;

	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], "", ""));

	if (pmstr[2] == "PROP_FLOAT")
		funcs.back().params.back().type = "float";

	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_property_array(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_array_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_array_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_negative_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_boolean_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_clear_flag(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_collection_active(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_collection_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_collection_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_duplicate_pointers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_dynamic_array_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_editable_array_func(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_editable_func(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_bitflag_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_items(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_py_data(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_enum_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_flag(vector<bpy_func> &funcs, string str)
{
	if (funcs.size() == 0) return true;
	if (funcs.back().error) return true;

	if (regex_search(str, regex("PROP_REQUIRED")))
		funcs.back().params.back().required = true;

	return true;
}

bool rna_def_property_float(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_float_array_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_float_array_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_float_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_float_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_float_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_float_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_free_identifier(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_free_pointers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_int_array_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_int_array_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_int_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_int_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_int_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_int_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_multi_array(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);

	regex reg1(R"(^.*_([\d+x]+).*$)");
	string dim_str = std::regex_replace(pmstr[2], reg1, "$1");
	vector<string> dim_vec = split(dim_str, regex("x"));

	for (string dim : dim_vec)
		funcs.back().params.back().name += "[" + dim + "]";

	return true;
}

bool rna_def_property_multidimensional_array(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_pointer_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_pointer_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_range(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_srna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_store(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_string_default(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_string_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_string_funcs_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_string_maxlength(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_string_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_struct_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_struct_type(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_subtype(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_translation_context(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_ui_icon(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_ui_range(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_ui_text(vector<bpy_func> &funcs, string str)
{
	if (funcs.size() == 0) return true;

	vector<string> pmstr = get_params(str);
	funcs.back().params.back().desc = pmstr[2];

	return true;
}

bool rna_def_property_update(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_property_update_runtime(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_py_data(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_render(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_rigidbody(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_rna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_scene(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_screen(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_sculpt_paint(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_sensor(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_sequencer(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_smoke(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_sound(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_space(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_speaker(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_string(vector<bpy_func> &funcs, string str)
{
	vector<string> pmstr = get_params(str);
	funcs.back().params.push_back(
		make_param(pmstr[1], "string", pmstr[5], "\"" + pmstr[2] + "\""));

	funcs.back().params.back().required = false;

	return true;
}

bool rna_def_string_dir_path(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_string_file_name(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_string_file_path(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_clear_flag(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_duplicate_pointers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_flag(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_free_pointers(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_identifier(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_idprops_func(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_name_property(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_nested(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_path_func(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_ptr(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_refine_func(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_register_funcs(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_sdna(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_sdna_from(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_translation_context(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_ui_icon(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_struct_ui_text(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_test(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_text(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_texture(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_timeline_marker(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_tracking(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_ui(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_userdef(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_vfont(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_wm(vector<bpy_func> &funcs, string str)
{
	return false;
}

bool rna_def_world(vector<bpy_func> &funcs, string str)
{
	return false;
}

/* RNA MAPPING */
void setup_enum_mapping()
{
	rna_def_map["rna_def_action"] = rna_def_action;
	rna_def_map["rna_def_actuator"] = rna_def_actuator;
	rna_def_map["rna_def_animation"] = rna_def_animation;
	rna_def_map["rna_def_animviz"] = rna_def_animviz;
	rna_def_map["rna_def_armature"] = rna_def_armature;
	rna_def_map["rna_def_boid"] = rna_def_boid;
	rna_def_map["rna_def_boolean"] = rna_def_boolean;
	rna_def_map["rna_def_boolean_array"] = rna_def_boolean_array;
	rna_def_map["rna_def_boolean_layer"] = rna_def_boolean_layer;
	rna_def_map["rna_def_boolean_layer_member"] = rna_def_boolean_layer_member;
	rna_def_map["rna_def_boolean_vector"] = rna_def_boolean_vector;
	rna_def_map["rna_def_brush"] = rna_def_brush;
	rna_def_map["rna_def_camera"] = rna_def_camera;
	rna_def_map["rna_def_cloth"] = rna_def_cloth;
	rna_def_map["rna_def_collection"] = rna_def_collection;
	rna_def_map["rna_def_collection_runtime"] = rna_def_collection_runtime;
	rna_def_map["rna_def_color"] = rna_def_color;
	rna_def_map["rna_def_constraint"] = rna_def_constraint;
	rna_def_map["rna_def_context"] = rna_def_context;
	rna_def_map["rna_def_controller"] = rna_def_controller;
	rna_def_map["rna_def_curve"] = rna_def_curve;
	rna_def_map["rna_def_dynamic_paint"] = rna_def_dynamic_paint;
	rna_def_map["rna_def_enum"] = rna_def_enum;
	rna_def_map["rna_def_enum_flag"] = rna_def_enum_flag;
	rna_def_map["rna_def_enum_funcs"] = rna_def_enum_funcs;
	rna_def_map["rna_def_fcurve"] = rna_def_fcurve;
	rna_def_map["rna_def_float"] = rna_def_float;
	rna_def_map["rna_def_float_array"] = rna_def_float_array;
	rna_def_map["rna_def_float_color"] = rna_def_float_color;
	rna_def_map["rna_def_float_factor"] = rna_def_float_factor;
	rna_def_map["rna_def_float_matrix"] = rna_def_float_matrix;
	rna_def_map["rna_def_float_percentage"] = rna_def_float_percentage;
	rna_def_map["rna_def_float_rotation"] = rna_def_float_rotation;
	rna_def_map["rna_def_float_vector"] = rna_def_float_vector;
	rna_def_map["rna_def_float_vector_xyz"] = rna_def_float_vector_xyz;
	rna_def_map["rna_def_fluidsim"] = rna_def_fluidsim;
	rna_def_map["rna_def_func_duplicate_pointers"] = rna_def_func_duplicate_pointers;
	rna_def_map["rna_def_func_free_pointers"] = rna_def_func_free_pointers;
	rna_def_map["rna_def_function"] = rna_def_function;
	rna_def_map["rna_def_function_flag"] = rna_def_function_flag;
	rna_def_map["rna_def_function_output"] = rna_def_function_output;
	rna_def_map["rna_def_function_return"] = rna_def_function_return;
	rna_def_map["rna_def_function_runtime"] = rna_def_function_runtime;
	rna_def_map["rna_def_function_ui_description"] = rna_def_function_ui_description;
	rna_def_map["rna_def_gameproperty"] = rna_def_gameproperty;
	rna_def_map["rna_def_gpencil"] = rna_def_gpencil;
	rna_def_map["rna_def_group"] = rna_def_group;
	rna_def_map["rna_def_id"] = rna_def_id;
	rna_def_map["rna_def_image"] = rna_def_image;
	rna_def_map["rna_def_int"] = rna_def_int;
	rna_def_map["rna_def_int_array"] = rna_def_int_array;
	rna_def_map["rna_def_int_vector"] = rna_def_int_vector;
	rna_def_map["rna_def_key"] = rna_def_key;
	rna_def_map["rna_def_lamp"] = rna_def_lamp;
	rna_def_map["rna_def_lattice"] = rna_def_lattice;
	rna_def_map["rna_def_linestyle"] = rna_def_linestyle;
	rna_def_map["rna_def_main"] = rna_def_main;
	rna_def_map["rna_def_main_actions"] = rna_def_main_actions;
	rna_def_map["rna_def_main_armatures"] = rna_def_main_armatures;
	rna_def_map["rna_def_main_brushes"] = rna_def_main_brushes;
	rna_def_map["rna_def_main_cameras"] = rna_def_main_cameras;
	rna_def_map["rna_def_main_curves"] = rna_def_main_curves;
	rna_def_map["rna_def_main_fonts"] = rna_def_main_fonts;
	rna_def_map["rna_def_main_gpencil"] = rna_def_main_gpencil;
	rna_def_map["rna_def_main_groups"] = rna_def_main_groups;
	rna_def_map["rna_def_main_images"] = rna_def_main_images;
	rna_def_map["rna_def_main_lamps"] = rna_def_main_lamps;
	rna_def_map["rna_def_main_lattices"] = rna_def_main_lattices;
	rna_def_map["rna_def_main_libraries"] = rna_def_main_libraries;
	rna_def_map["rna_def_main_linestyles"] = rna_def_main_linestyles;
	rna_def_map["rna_def_main_masks"] = rna_def_main_masks;
	rna_def_map["rna_def_main_materials"] = rna_def_main_materials;
	rna_def_map["rna_def_main_meshes"] = rna_def_main_meshes;
	rna_def_map["rna_def_main_metaballs"] = rna_def_main_metaballs;
	rna_def_map["rna_def_main_movieclips"] = rna_def_main_movieclips;
	rna_def_map["rna_def_main_node_groups"] = rna_def_main_node_groups;
	rna_def_map["rna_def_main_objects"] = rna_def_main_objects;
	rna_def_map["rna_def_main_particles"] = rna_def_main_particles;
	rna_def_map["rna_def_main_scenes"] = rna_def_main_scenes;
	rna_def_map["rna_def_main_screens"] = rna_def_main_screens;
	rna_def_map["rna_def_main_sounds"] = rna_def_main_sounds;
	rna_def_map["rna_def_main_speakers"] = rna_def_main_speakers;
	rna_def_map["rna_def_main_texts"] = rna_def_main_texts;
	rna_def_map["rna_def_main_textures"] = rna_def_main_textures;
	rna_def_map["rna_def_main_window_managers"] = rna_def_main_window_managers;
	rna_def_map["rna_def_main_worlds"] = rna_def_main_worlds;
	rna_def_map["rna_def_mask"] = rna_def_mask;
	rna_def_map["rna_def_material"] = rna_def_material;
	rna_def_map["rna_def_mesh"] = rna_def_mesh;
	rna_def_map["rna_def_meta"] = rna_def_meta;
	rna_def_map["rna_def_modifier"] = rna_def_modifier;
	rna_def_map["rna_def_movieclip"] = rna_def_movieclip;
	rna_def_map["rna_def_nla"] = rna_def_nla;
	rna_def_map["rna_def_nodetree"] = rna_def_nodetree;
	rna_def_map["rna_def_object"] = rna_def_object;
	rna_def_map["rna_def_object_force"] = rna_def_object_force;
	rna_def_map["rna_def_packedfile"] = rna_def_packedfile;
	rna_def_map["rna_def_particle"] = rna_def_particle;
	rna_def_map["rna_def_pointer"] = rna_def_pointer;
	rna_def_map["rna_def_pointer_runtime"] = rna_def_pointer_runtime;
	rna_def_map["rna_def_pose"] = rna_def_pose;
	rna_def_map["rna_def_property"] = rna_def_property;
	rna_def_map["rna_def_property_array"] = rna_def_property_array;
	rna_def_map["rna_def_property_boolean_array_default"] = rna_def_property_boolean_array_default;
	rna_def_map["rna_def_property_boolean_array_funcs_runtime"] = rna_def_property_boolean_array_funcs_runtime;
	rna_def_map["rna_def_property_boolean_default"] = rna_def_property_boolean_default;
	rna_def_map["rna_def_property_boolean_funcs"] = rna_def_property_boolean_funcs;
	rna_def_map["rna_def_property_boolean_funcs_runtime"] = rna_def_property_boolean_funcs_runtime;
	rna_def_map["rna_def_property_boolean_negative_sdna"] = rna_def_property_boolean_negative_sdna;
	rna_def_map["rna_def_property_boolean_sdna"] = rna_def_property_boolean_sdna;
	rna_def_map["rna_def_property_clear_flag"] = rna_def_property_clear_flag;
	rna_def_map["rna_def_property_collection_active"] = rna_def_property_collection_active;
	rna_def_map["rna_def_property_collection_funcs"] = rna_def_property_collection_funcs;
	rna_def_map["rna_def_property_collection_sdna"] = rna_def_property_collection_sdna;
	rna_def_map["rna_def_property_duplicate_pointers"] = rna_def_property_duplicate_pointers;
	rna_def_map["rna_def_property_dynamic_array_funcs"] = rna_def_property_dynamic_array_funcs;
	rna_def_map["rna_def_property_editable_array_func"] = rna_def_property_editable_array_func;
	rna_def_map["rna_def_property_editable_func"] = rna_def_property_editable_func;
	rna_def_map["rna_def_property_enum_bitflag_sdna"] = rna_def_property_enum_bitflag_sdna;
	rna_def_map["rna_def_property_enum_default"] = rna_def_property_enum_default;
	rna_def_map["rna_def_property_enum_funcs"] = rna_def_property_enum_funcs;
	rna_def_map["rna_def_property_enum_funcs_runtime"] = rna_def_property_enum_funcs_runtime;
	rna_def_map["rna_def_property_enum_items"] = rna_def_property_enum_items;
	rna_def_map["rna_def_property_enum_py_data"] = rna_def_property_enum_py_data;
	rna_def_map["rna_def_property_enum_sdna"] = rna_def_property_enum_sdna;
	rna_def_map["rna_def_property_flag"] = rna_def_property_flag;
	rna_def_map["rna_def_property_float"] = rna_def_property_float;
	rna_def_map["rna_def_property_float_array_default"] = rna_def_property_float_array_default;
	rna_def_map["rna_def_property_float_array_funcs_runtime"] = rna_def_property_float_array_funcs_runtime;
	rna_def_map["rna_def_property_float_default"] = rna_def_property_float_default;
	rna_def_map["rna_def_property_float_funcs"] = rna_def_property_float_funcs;
	rna_def_map["rna_def_property_float_funcs_runtime"] = rna_def_property_float_funcs_runtime;
	rna_def_map["rna_def_property_float_sdna"] = rna_def_property_float_sdna;
	rna_def_map["rna_def_property_free_identifier"] = rna_def_property_free_identifier;
	rna_def_map["rna_def_property_free_pointers"] = rna_def_property_free_pointers;
	rna_def_map["rna_def_property_int_array_default"] = rna_def_property_int_array_default;
	rna_def_map["rna_def_property_int_array_funcs_runtime"] = rna_def_property_int_array_funcs_runtime;
	rna_def_map["rna_def_property_int_default"] = rna_def_property_int_default;
	rna_def_map["rna_def_property_int_funcs"] = rna_def_property_int_funcs;
	rna_def_map["rna_def_property_int_funcs_runtime"] = rna_def_property_int_funcs_runtime;
	rna_def_map["rna_def_property_int_sdna"] = rna_def_property_int_sdna;
	rna_def_map["rna_def_property_multi_array"] = rna_def_property_multi_array;
	rna_def_map["rna_def_property_multidimensional_array"] = rna_def_property_multidimensional_array;
	rna_def_map["rna_def_property_pointer_funcs"] = rna_def_property_pointer_funcs;
	rna_def_map["rna_def_property_pointer_sdna"] = rna_def_property_pointer_sdna;
	rna_def_map["rna_def_property_range"] = rna_def_property_range;
	rna_def_map["rna_def_property_srna"] = rna_def_property_srna;
	rna_def_map["rna_def_property_store"] = rna_def_property_store;
	rna_def_map["rna_def_property_string_default"] = rna_def_property_string_default;
	rna_def_map["rna_def_property_string_funcs"] = rna_def_property_string_funcs;
	rna_def_map["rna_def_property_string_funcs_runtime"] = rna_def_property_string_funcs_runtime;
	rna_def_map["rna_def_property_string_maxlength"] = rna_def_property_string_maxlength;
	rna_def_map["rna_def_property_string_sdna"] = rna_def_property_string_sdna;
	rna_def_map["rna_def_property_struct_runtime"] = rna_def_property_struct_runtime;
	rna_def_map["rna_def_property_struct_type"] = rna_def_property_struct_type;
	rna_def_map["rna_def_property_subtype"] = rna_def_property_subtype;
	rna_def_map["rna_def_property_translation_context"] = rna_def_property_translation_context;
	rna_def_map["rna_def_property_ui_icon"] = rna_def_property_ui_icon;
	rna_def_map["rna_def_property_ui_range"] = rna_def_property_ui_range;
	rna_def_map["rna_def_property_ui_text"] = rna_def_property_ui_text;
	rna_def_map["rna_def_property_update"] = rna_def_property_update;
	rna_def_map["rna_def_property_update_runtime"] = rna_def_property_update_runtime;
	rna_def_map["rna_def_py_data"] = rna_def_py_data;
	rna_def_map["rna_def_render"] = rna_def_render;
	rna_def_map["rna_def_rigidbody"] = rna_def_rigidbody;
	rna_def_map["rna_def_rna"] = rna_def_rna;
	rna_def_map["rna_def_scene"] = rna_def_scene;
	rna_def_map["rna_def_screen"] = rna_def_screen;
	rna_def_map["rna_def_sculpt_paint"] = rna_def_sculpt_paint;
	rna_def_map["rna_def_sensor"] = rna_def_sensor;
	rna_def_map["rna_def_sequencer"] = rna_def_sequencer;
	rna_def_map["rna_def_smoke"] = rna_def_smoke;
	rna_def_map["rna_def_sound"] = rna_def_sound;
	rna_def_map["rna_def_space"] = rna_def_space;
	rna_def_map["rna_def_speaker"] = rna_def_speaker;
	rna_def_map["rna_def_string"] = rna_def_string;
	rna_def_map["rna_def_string_dir_path"] = rna_def_string_dir_path;
	rna_def_map["rna_def_string_file_name"] = rna_def_string_file_name;
	rna_def_map["rna_def_string_file_path"] = rna_def_string_file_path;
	rna_def_map["rna_def_struct"] = rna_def_struct;
	rna_def_map["rna_def_struct_clear_flag"] = rna_def_struct_clear_flag;
	rna_def_map["rna_def_struct_duplicate_pointers"] = rna_def_struct_duplicate_pointers;
	rna_def_map["rna_def_struct_flag"] = rna_def_struct_flag;
	rna_def_map["rna_def_struct_free_pointers"] = rna_def_struct_free_pointers;
	rna_def_map["rna_def_struct_identifier"] = rna_def_struct_identifier;
	rna_def_map["rna_def_struct_idprops_func"] = rna_def_struct_idprops_func;
	rna_def_map["rna_def_struct_name_property"] = rna_def_struct_name_property;
	rna_def_map["rna_def_struct_nested"] = rna_def_struct_nested;
	rna_def_map["rna_def_struct_path_func"] = rna_def_struct_path_func;
	rna_def_map["rna_def_struct_ptr"] = rna_def_struct_ptr;
	rna_def_map["rna_def_struct_refine_func"] = rna_def_struct_refine_func;
	rna_def_map["rna_def_struct_register_funcs"] = rna_def_struct_register_funcs;
	rna_def_map["rna_def_struct_sdna"] = rna_def_struct_sdna;
	rna_def_map["rna_def_struct_sdna_from"] = rna_def_struct_sdna_from;
	rna_def_map["rna_def_struct_translation_context"] = rna_def_struct_translation_context;
	rna_def_map["rna_def_struct_ui_icon"] = rna_def_struct_ui_icon;
	rna_def_map["rna_def_struct_ui_text"] = rna_def_struct_ui_text;
	rna_def_map["rna_def_test"] = rna_def_test;
	rna_def_map["rna_def_text"] = rna_def_text;
	rna_def_map["rna_def_texture"] = rna_def_texture;
	rna_def_map["rna_def_timeline_marker"] = rna_def_timeline_marker;
	rna_def_map["rna_def_tracking"] = rna_def_tracking;
	rna_def_map["rna_def_ui"] = rna_def_ui;
	rna_def_map["rna_def_userdef"] = rna_def_userdef;
	rna_def_map["rna_def_vfont"] = rna_def_vfont;
	rna_def_map["rna_def_wm"] = rna_def_wm;
	rna_def_map["rna_def_world"] = rna_def_world;
}