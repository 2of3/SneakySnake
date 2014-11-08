#include <Python.h>

// VARIABLES

static PyObject *uniplug_callback = NULL;

// METHODS

static PyObject *
uniplug_add(PyObject *self, PyObject *args)
{
	int valx;
	int valy;

	if (!PyArg_ParseTuple(args, "ii", &valx, &valy))
		return NULL;

	return PyLong_FromLong(valx + valy);
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
	{ "add", uniplug_add, METH_VARARGS,
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