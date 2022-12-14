#include <pybind11/pybind11.h>
#include "analytic/digital_option.h"
#include "analytic/vanilla_option.h"

namespace py = pybind11;

PYBIND11_MODULE(venus, m){
    py::enum_<OptionType>(m, "option_type")
            .value("call", OptionType::Call)
            .value("put", OptionType::Put);

    py::module m2 = m.def_submodule("vanilla_pricer", "vanilla pricer from venus");
    m2.def("price", &vanilla_pricer::price);
    m2.def("delta", &vanilla_pricer::delta);
    m2.def("gamma", &vanilla_pricer::gamma);
    m2.def("vega", &vanilla_pricer::vega);
    m2.def("theta", &vanilla_pricer::theta);
    m2.def("rho", &vanilla_pricer::rho);
    m2.def("phi", &vanilla_pricer::phi);

    py::module m3 = m.def_submodule("digital_pricer", "digital pricer from venus");
    m3.def("price", &digital_pricer::price);
    m3.def("delta", &digital_pricer::delta);
    m3.def("gamma", &digital_pricer::gamma);
    m3.def("vega", &digital_pricer::vega);
    m3.def("theta", &digital_pricer::theta);
    m3.def("rho", &digital_pricer::rho);
    m3.def("phi", &digital_pricer::phi);
}
