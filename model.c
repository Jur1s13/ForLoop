#define _CRT_SECURE_NO_WARNINGS
#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject*
ForLoop(PyObject* self, PyObject* args)
{
    int i;
    int n;
    int res = 0;
    float sum = 0;
    printf("Please enter the value of i");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        sum += 1 / (float)i;
    }
    printf("%f\n", sum);
    res = PyArg_ParseTuple(args, "s", &sum);
    return PyFloat_FromDouble(res);
    /*return null;*/
}

static PyMethodDef ForLoopMethods[] = {
    {"ForLoop",  ForLoop, METH_VARARGS, "Returns the For Loop."},
    {NULL}
};

static struct PyModuleDef for_loop_module = {
    PyModuleDef_HEAD_INIT,
    "ForLoopModule",       /* The module name (in Python) */
    "A module with a for loop", /* Module docstring. */
    -1,                 /* See the docs for this one! */
    ForLoopMethods    /* This module's methods. */
};

PyMODINIT_FUNC
PyInit_ForLoopModule(void)
{
    return PyModule_Create(&for_loop_module);
}