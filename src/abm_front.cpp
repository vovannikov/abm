#include "abm.h"
#include "abm_front.h"
#include "tools/global.h"

// Main model itself
template <int dim>
ABMFront<dim>::ABMFront(double length, double patch_size, double D1, double D4, std::string savePath)
    : _abm(nullptr)
{
    std::cout << "Building ABM frontend ..." << std::endl;
    TOOLS::initGlobals();
    _abm = std::make_unique<ABM<dim>>(length, patch_size, D1, D4, savePath);
}

// Main model itself
template <int dim>
ABMFront<dim>::~ABMFront()
{
    TOOLS::timer::instance().print_summary();
}

template <int dim>
std::vector<double> ABMFront<dim>::run(const std::vector<double>& vecInitVals, double timeStepInit, double timeEnd)
{
    return _abm->run(vecInitVals, timeStepInit, timeEnd);
}

template class ABMFront<2>;
template class ABMFront<3>;
