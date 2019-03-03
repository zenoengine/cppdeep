#include <iostream>

#define MAX2(a,b ) (a) > (b) ? (a) : (b)

class Neuron
{
public:
    enum class ActivationType
    {
        Identity,
        ReLU,
        Invalid,
    };

    Neuron(){};
    ~Neuron(){};

    ActivationType activationType = ActivationType::ReLU;
    double w = 0.f;
    double b = 0.f;
    
    double feedForward(double const & x)
    {
        double const sigma = w*x + b;
        return getActivation(sigma);
    }

    double getActivation(double const & x)
    {
        switch(activationType)
        {
            case ActivationType::Identity:
            {
              return x;  
            }
            break;
            case ActivationType::ReLU:
            {
                return MAX2(0.0f, x);
            }
            break;
        }
    }
};

int main()
{
    Neuron neuron;
    neuron.w = 2.0f;
    neuron.b = 1.0f;
    
    std::cout << "Input = 0.0 " << neuron.feedForward(0g.0) << std::endl;
    std::cout << "Input = 1.0 " << neuron.feedForward(1.0) << std::endl;
    std::cout << "Input = 2.0 " << neuron.feedForward(2.0) << std::endl;
    std::cout << "Input = 3.0 " << neuron.feedForward(3.0) << std::endl;
    return 0;
}