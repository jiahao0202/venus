#include <pybind11/pybind11.h>
#include "analytic/vanilla_option.h"

namespace py = pybind11;

PYBIND11_MODULE(venus, m){
    py::enum_<OptionType>(m, "option_type")
            .value("call", OptionType::Call)
            .value("put", OptionType::Put);
}
