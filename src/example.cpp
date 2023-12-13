#include "numerical_tool.hpp"
#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>

int main(int argc, char** argv) {

    // ros initialization
    ros::init(argc, argv, "code_trials_node");
    ros::NodeHandle nh;
    double Hz = 50.0;
    int data_size = 6;
    ros::Rate rate(Hz);

    // publishing parameters
    ros::Publisher data_pub = nh.advertise<std_msgs::Float64MultiArray>("/generated_data", 10);
    ros::Publisher integral_pub = nh.advertise<std_msgs::Float64MultiArray>("/integrated_data", 10);
    ros::Publisher derivative_pub = nh.advertise<std_msgs::Float64MultiArray>("/derivated_data", 10);
    
    std::vector<double> generated_data;
    Eigen::VectorXd generated_vector(data_size);
    generated_data.resize(data_size);
    std_msgs::Float64MultiArray generated_msg;

    std::vector<double> integrated_data;
    Eigen::VectorXd integrated_vector(data_size);
    integrated_data.resize(data_size);
    std_msgs::Float64MultiArray integrated_msg;

    std::vector<double> derivated_data;
    Eigen::VectorXd derivated_vector(data_size);
    derivated_data.resize(data_size);
    std_msgs::Float64MultiArray derivated_msg;

    // class initializations
    NumericalTool integrator;
    NumericalTool derivator;
    double dt = 1.0/Hz;
    integrator.init_integration(dt, data_size);
    derivator.init_derivation(dt, data_size);

    // loop definitions
    double increment = 0.01;
    double counter = 0;

    while (ros::ok()) 
    {   

        // generated data publishing
        for (size_t i = 0; i < data_size; i++)
        {
            generated_data[i] = counter;
            generated_vector(i) = counter;
        }
        generated_msg.data = generated_data;
        data_pub.publish(generated_msg);

        // integral operations
        integrated_vector = integrator.integrate(generated_vector);
        for (size_t i = 0; i < data_size; i++)
        {
            integrated_data[i] = integrated_vector(i);
        }
        integrated_msg.data = integrated_data;
        integral_pub.publish(integrated_msg);

        // derivative operations
        derivated_vector = derivator.derive(generated_vector);
        for (size_t i = 0; i < data_size; i++)
        {
            derivated_data[i] = derivated_vector(i);
        }
        derivated_msg.data = derivated_data;
        derivative_pub.publish(derivated_msg);

        // loop cycling
        if ((counter > 1) || (counter < -1)) {
            increment = increment * -1;
        }
        counter = counter + increment;
        rate.sleep();
    }
    
    return 0;
}
