#include <Python.h>
#include <string>

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

static PyObject *
uniplug_test(PyObject *self, PyObject *args)
{
	PyObject *pName = Py_BuildValue("s", "bpy");
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

	Py_INCREF(Py_None);
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

// INITIALIZATION

static PyMethodDef UniplugMethods[] = {
		{ "test", uniplug_test, METH_VARARGS,
	"Addition of two given integers." },
	{ "basics", uniplug_basics, METH_VARARGS,
	"Basic math operations on two given integers." },
	{ "set_callback", uniplug_set_callback, METH_VARARGS,
	"Sets a callback on a given method." },
	{ "call_callback", uniplug_call_callback, METH_VARARGS,
	"Calls a set callback with the given args." },
	{NULL, NULL, 0, NULL}        /* sentinel */
};

static struct PyModuleDef uniplugmodule = {
	PyModuleDef_HEAD_INIT,
	"uniplug",  /* name of module */
	NULL,	  /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
			     or -1 if the module keeps state in global variables. */
	UniplugMethods
};

PyMODINIT_FUNC
PyInit_uniplug(void)
{
	return PyModule_Create(&uniplugmodule);
}