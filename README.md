# Numeric-Tool-Library
Numerical analysis tool including integration and derivation in C++ with Eigen Library.

Functionalities:
---
- Integration
- Derivation

Integrator Usage:
---
```
double Hz = 50.0;
double dt = 1.0/Hz;
int data_size = 6;

NumericalTool integrator;
integrator.init_integration(dt, data_size);
integrated_vector = integrator.integrate(generated_vector);
```

Derivator Usage:
---
```
double Hz = 50.0;
double dt = 1.0/Hz;
int data_size = 6;

NumericalTool derivator;
derivator.init_derivation(dt, data_size);
derivated_vector = derivator.derive(generated_vector);
```