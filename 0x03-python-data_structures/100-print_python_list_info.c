#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - prints python list info
 *
 * @p: PyObject
 * Return: no return
 */
void print_python_list_info(PyObject *p)
{
    long int size, i;
    PyListObject *list;
    PyObject *item;

    if (!PyList_Check(p))
    {
        fprintf(stderr, "[*] Invalid List Object\n");
        return;
    }

    size = Py_SIZE(p);
    printf("[*] Size of the Python List = %ld\n", size);

    list = (PyListObject *)p;
    printf("[*] Allocated = %ld\n", list->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        if (item == NULL)
        {
            fprintf(stderr, "Element %ld: Failed to retrieve\n", i);
        }
        else
        {
            printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        }
    }
}
