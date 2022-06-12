#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class Fib {
 public:
  Fib(int n) : n(n) {
  }

  int run() {
    if (n <= 0) {
      return 0;
    } else if (n == 1 or n == 2) {
      return 1;
    }

    return Fib(n-1).run() + Fib(n-2).run();
  }

  int n;
};

PYBIND11_MODULE(hle, m) {
  py::class_<Fib>(m, "Fib")
      .def(py::init<int>())
      .def("run", &Fib::run, py::call_guard<py::gil_scoped_release>());

}
