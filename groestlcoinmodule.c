#include <Python.h>


#include "groestlcoin.h"


static PyObject *groestlcoin_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);


#if PY_MAJOR_VERSION >= 3
    groestlcoin_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    groestlcoin_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}


static PyMethodDef groestlcoinMethods[] = {
    { "getPoWHash", groestlcoin_getpowhash, METH_VARARGS, "Returns the proof of work hash using groestlcoin hash" },
    { NULL, NULL, 0, NULL }
};


#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef groestlcoinModule = {
    PyModuleDef_HEAD_INIT,
    "groestlcoin_hash",
    "...",
    -1,
    groestlcoinMethods
};


PyMODINIT_FUNC PyInit_groestlcoin_hash(void) {
    return PyModule_Create(&groestlcoinModule);
}


#else


PyMODINIT_FUNC initgroestlcoin_hash(void) {
    (void) Py_InitModule("groestlcoin_hash", groestlcoinMethods);
}
#endif


