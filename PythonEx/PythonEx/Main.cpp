#include <Python.h>
#include "uniplug_blender_api.h"
#include <string>
#include <iostream>

using namespace UniplugBL;

static PyObject *
uniplug_getpos(PyObject *self, PyObject *args)
{
	Scene scene = pyUniplug().context().scene();
	std::map<std::string, Object> objects = scene.objects();

	Object cube = objects["Cube"];

	std::array<float, 3> loc = cube.location();
	bool select = cube.select();

	std::string output = "print('Position: x = " + std::to_string(loc[0]) +
		"; y = " + std::to_string(loc[1]) + "; z = " + std::to_string(loc[2]) +
		" - Select: " + (select ? "true" : "false") + "')\n";
	PyRun_SimpleString(output.c_str());

	for (std::map<std::string, Object>::iterator it = objects.begin(); it != objects.end(); ++it)
		it->second.select(false);

	cube.select(true);

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
uniplug_reset(PyObject *self, PyObject *args)
{
	PyObject *pModule, *pData, *pObjects, *pCube, *pArgs;

	pModule = PyImport_ImportModule("bpy");

	pData = PyObject_GetAttrString(pModule, "data");
	pObjects = PyObject_GetAttrString(pData, "objects");
	pCube = PySequence_GetItem(pObjects, 1);

	pArgs = Py_BuildValue("(fff)", 0.0f, 0.0f, 0.0f);
	PyObject_SetAttrString(pCube, "location", pArgs);

	Py_DECREF(pModule);
	Py_DECREF(pData);
	Py_DECREF(pObjects);
	Py_DECREF(pCube);
	Py_DECREF(pArgs);

	Py_INCREF(Py_None);
	return Py_None;
}

// INITIALIZATION

static PyMethodDef UniplugMethods[] = {
		{ "getpos", uniplug_getpos, METH_VARARGS, "---" },
		{ "reest", uniplug_reset, METH_VARARGS, "---" },
		{ NULL, NULL, 0, NULL }
};

static struct PyModuleDef uniplugmodule = {
	PyModuleDef_HEAD_INIT,
	"uniplug",  /* name of module */
	NULL,	    /* module documentation, may be NULL */
	-1,         /* module keeps state in global variables. */
	UniplugMethods		/* method definition table, may be NULL */
};

PyMODINIT_FUNC
PyInit_uniplug(void)
{
	return PyModule_Create(&uniplugmodule);
}

/*


/*
if (pFunc && PyCallable_Check(pFunc)) {

pContext = PyObject_GetAttrString(pModule, "context");
pScene = PyObject_GetAttrString(pContext, "scene");

pArgs = Py_BuildValue("(Oisi)", pScene, false, "RENDER", false);
pMesh = PyObject_CallObject(pFunc, pArgs);

pVertices = PyObject_GetAttrString(pMesh, "vertices");
pPoint = PySequence_GetItem(pVertices, 0);
pCo = PyObject_GetAttrString(pPoint, "co");
pX = PyObject_GetAttrString(pCo, "x");

PyObject_Print(pCo, stdout, Py_PRINT_RAW);

const int pXVal = PyLong_AsLong(pX);

std::string output = "print('Position of x: " + std::to_string(pXVal) + "')\n";
PyRun_SimpleString(output.c_str());
*/

/*	// Py_DECREF(pArgs);
// Py_DECREF(pReturn);
}
else
PyErr_Print();



// VARIABLES

static PyObject *uniplug_callback = NULL;

// METHODS


static std::string 
ConvertToStr(PyObject *obj)
{
	PyObject *objDesc = PyObject_Str(obj);

	std::string objStr;

	if (PyUnicode_Check(objDesc)) {
		PyObject * temp_bytes = PyUnicode_AsEncodedString(objDesc, "ASCII", "strict");

		if (temp_bytes != NULL) {
			objStr = PyBytes_AS_STRING(temp_bytes);
			Py_DECREF(temp_bytes);
		}
	}

	return objStr;
}

static void
FormatReader(const char *format)
{
	std::string formatStr(format);
	formatStr = "print(\"" + formatStr + "\")";
	PyRun_SimpleString(formatStr.c_str());
}

static PyObject *
uniplug_test(PyObject *self, PyObject *args)
{
	PyArg_SetUniplugCB(&FormatReader);
	PyRun_SimpleString("print('Callback gesetzt.')");

	/*PyObject *pName = Py_BuildValue("s", "bpy");
	PyObject *pModule = PyImport_Import(pName);

	PyObject *pDict = PyModule_GetDict(pModule);
	//PyObject *key, *value;

	PyObject *obj;

	PyArg_ParseTuple(args, "O", &obj);

	/*
	std::string outputStr;

	if (PyCallable_Check(obj)) {
		PyRun_SimpleString("print('is callable')");
		PyObject* fc = PyObject_GetAttrString(obj, "func_code");

		if (fc) {
			outputStr = ConvertToStr(fc);
			outputStr = "print(\"" + outputStr + "\")";
			PyRun_SimpleString(outputStr.c_str());
		}
	}

	outputStr = "print(\"" + outputStr + "\")";

	PyRun_SimpleString(outputStr.c_str());*/

	//Py_ssize_t pos = 0;

	/*
	while (PyDict_Next(pDict, &pos, &key, &value)) {
		std::string keyStr = ConvertToStr(key);
		std::string valStr = key->ob_type->tp_name;

		std::string outputStr = "Key " + keyStr + " -> " + valStr + ":";
		outputStr = "print(\"" + outputStr + "\")";

		PyRun_SimpleString(outputStr.c_str());

		if (PyCallable_Check(value)) {
			PyObject* fc = PyObject_GetAttrString(value, "func_code");

			if (fc) {
				outputStr = "print(\"" + outputStr + "\")";
				PyRun_SimpleString(outputStr.c_str());
			}
		}

		/*	if (fc) {
				PyObject* ac = PyObject_GetAttrString(fc, "co_argcount");

				if (ac) {
					const int count = PyLong_AsLong(ac);

					 = "print('" + pDict + "')";
					PyRun_SimpleString(outputStr.c_str());

					Py_DECREF(ac);
				}
				Py_DECREF(fc);
			}
	}
	*/

/*	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
uniplug_basics(PyObject *self, PyObject *args)
{
	int valx;
	int valy;

	if (!PyArg_ParseTuple(args, "ii", &valx, &valy))
		return NULL;

	int sum = valx + valy;
	int diff = valx - valy;
	int prod = valx * valy;
	float quot = (float) valx / (float) valy;

	return Py_BuildValue("iiif", sum, diff, prod, quot);
}

static PyObject *
uniplug_set_callback(PyObject *self, PyObject *args)
{
	PyObject *result = NULL;
	PyObject *temp;

	if (PyArg_ParseTuple(args, "O:set_callback", &temp)) {
		if (!PyCallable_Check(temp)) {
			PyErr_SetString(PyExc_TypeError, "parameter must be callable");
			return NULL;
		}

		Py_XINCREF(temp);
		Py_XDECREF(uniplug_callback);
		uniplug_callback = temp;

		Py_INCREF(Py_None);
		result = Py_None;
	}

	return result;
}

static PyObject *
uniplug_call_callback(PyObject *self, PyObject *args)
{
	return PyObject_CallObject(uniplug_callback, args);
}


*/