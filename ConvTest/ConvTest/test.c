	static EnumPropertyItem mesh_type_items[] = {
		{eModifierMode_Realtime, "PREVIEW", 0, "Preview", "Apply modifier preview settings"},
		{eModifierMode_Render, "RENDER", 0, "Render", "Apply modifier render settings"},
		{0, NULL, 0, NULL, NULL}
	};

	static EnumPropertyItem dupli_eval_mode_items[] = {
		{DAG_EVAL_VIEWPORT, "VIEWPORT", 0, "Viewport", "Generate duplis using viewport settings"},
		{DAG_EVAL_PREVIEW, "PREVIEW", 0, "Preview", "Generate duplis using preview settings"},
		{DAG_EVAL_RENDER, "RENDER", 0, "Render", "Generate duplis using render settings"},
		{0, NULL, 0, NULL, NULL}
	};

#ifndef NDEBUG
	static EnumPropertyItem mesh_dm_info_items[] = {
		{0, "SOURCE", 0, "Source", "Source mesh"},
		{1, "DEFORM", 0, "Deform", "Objects deform mesh"},
		{2, "FINAL", 0, "Final", "Objects final mesh"},
		{0, NULL, 0, NULL, NULL}
	};
#endif

	/* mesh */
	func = RNA_def_function(srna, "to_mesh", "rna_Object_to_mesh");
	RNA_def_function_ui_description(func, "Create a Mesh datablock with modifiers applied");
	RNA_def_function_flag(func, FUNC_USE_REPORTS);
	parm = RNA_def_pointer(func, "scene", "Scene", "", "Scene within which to evaluate modifiers");
	RNA_def_property_flag(parm, PROP_REQUIRED | PROP_NEVER_NULL);
	parm = RNA_def_boolean(func, "apply_modifiers", 0, "", "Apply modifiers");
	RNA_def_property_flag(parm, PROP_REQUIRED);
	parm = RNA_def_enum(func, "settings", mesh_type_items, 0, "", "Modifier settings to apply");
	RNA_def_property_flag(parm, PROP_REQUIRED);
	RNA_def_boolean(func, "calc_tessface", true, "Calculate Tessellation", "Calculate tessellation faces");
	RNA_def_boolean(func, "calc_undeformed", false, "Calculate Undeformed", "Calculate undeformed vertex coordinates");
	parm = RNA_def_pointer(func, "mesh", "Mesh", "",
	                       "Mesh created from object, remove it if it is only used for export");
	RNA_def_function_return(func, parm);
	
	/* duplis */
	func = RNA_def_function(srna, "dupli_list_create", "rna_Object_create_duplilist");
	RNA_def_function_ui_description(func, "Create a list of dupli objects for this object, needs to "
	                                "be freed manually with free_dupli_list to restore the "
	                                "objects real matrix and layers");
	parm = RNA_def_pointer(func, "scene", "Scene", "", "Scene within which to evaluate duplis");
	RNA_def_property_flag(parm, PROP_REQUIRED | PROP_NEVER_NULL);
	RNA_def_enum(func, "settings", dupli_eval_mode_items, 0, "", "Generate texture coordinates for rendering");
	RNA_def_function_flag(func, FUNC_USE_REPORTS);

	func = RNA_def_function(srna, "dupli_list_clear", "rna_Object_free_duplilist");
	RNA_def_function_ui_description(func, "Free the list of dupli objects");

	/* Armature */
	func = RNA_def_function(srna, "find_armature", "modifiers_isDeformedByArmature");
	RNA_def_function_ui_description(func, "Find armature influencing this object as a parent or via a modifier");
	parm = RNA_def_pointer(func, "ob_arm", "Object", "", "Armature object influencing this object or NULL");
	RNA_def_function_return(func, parm);

	/* Shape key */
	func = RNA_def_function(srna, "shape_key_add", "rna_Object_shape_key_add");
	RNA_def_function_ui_description(func, "Add shape key to an object");
	RNA_def_function_flag(func, FUNC_USE_CONTEXT | FUNC_USE_REPORTS);
	RNA_def_string(func, "name", "Key", 0, "", "Unique name for the new keylock"); /* optional */
	RNA_def_boolean(func, "from_mix", 1, "", "Create new shape from existing mix of shapes");
	parm = RNA_def_pointer(func, "key", "ShapeKey", "", "New shape keyblock");
	RNA_def_property_flag(parm, PROP_RNAPTR);
	RNA_def_function_return(func, parm);