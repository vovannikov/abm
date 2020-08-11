#include <vector>
#include <string>
#include <memory>

// This is a pimpl wrapper

// Forward declaration of the ABM model
template <int dim>
class ABM;

template <int dim>
class ABMFront
{
private:
    std::unique_ptr<ABM<dim>> _abm;

public:
    ABMFront(double length, double patch_size, double D1, double D4, std::string savePath = std::string());

    ~ABMFront();

    std::vector<double> run(const std::vector<double>& vecInitVals, double timeStepInit, double timeEnd);
};
