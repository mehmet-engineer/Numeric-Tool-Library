#include <iostream>
#include <eigen3/Eigen/Dense>

/**
 * @author: Mehmet Kahraman
 * @date: 13.12.2023
 * @about: Numerical analysis tool including integration and derivation
*/

class NumericalTool {

    public:

        // general definitions
        double dt;
        int data_size;
        bool first_cycle;

        // integral definitions
        Eigen::VectorXd delta_x;
        Eigen::VectorXd integral_data;

        // derivative definitions
        Eigen::VectorXd derivative_data;
        Eigen::VectorXd prev_data;
        Eigen::VectorXd diff;

    // constructor
    NumericalTool() {
        // initial values
        dt = 1/50; // dt = 0.02
        data_size = 1;
        first_cycle = true;
    };

    // member functions
    void init_integration(double dt, int data_size);
    Eigen::VectorXd integrate(Eigen::VectorXd data);

    void init_derivation(double dt, int data_size);
    Eigen::VectorXd derive(Eigen::VectorXd data);

};  // class
