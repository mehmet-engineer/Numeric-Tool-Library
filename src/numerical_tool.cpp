#include "numerical_tool.hpp"

/**
 * @author: Mehmet Kahraman
 * @date: 13.12.2023
 * @about: Numerical analysis tool including integration and derivation
*/

void NumericalTool::init_integration(double dt, int data_size) 
{
    
    this->dt = dt;
    this->data_size = data_size;

    delta_x.resize(data_size);
    integral_data.resize(data_size);

}

void NumericalTool::init_derivation(double dt, int data_size) 
{
    
    this->dt = dt;
    this->data_size = data_size;

    derivative_data.resize(data_size);
    prev_data.resize(data_size);
    diff.resize(data_size);

}

Eigen::VectorXd NumericalTool::integrate(Eigen::VectorXd data) 
{

    if (first_cycle == true)  {

        first_cycle = false;
        integral_data = data;
        return integral_data;
    }
    
    else {

        delta_x = data * dt;
        integral_data = integral_data + delta_x;
        return integral_data;
    }

}

Eigen::VectorXd NumericalTool::derive(Eigen::VectorXd data)
{

    if (first_cycle == true)  {

        first_cycle = false;
        derivative_data = data / dt;
        prev_data = data;
        return derivative_data;
    }
    
    else {

        diff = data - prev_data;
        derivative_data = diff / dt;
        prev_data = data;
        return derivative_data;
    }

}

