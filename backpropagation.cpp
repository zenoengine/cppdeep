#include <iostream>
#include <assert.h>

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

    ActivationType activationType = ActivationType::Identity;
    double w = 0.f;
    double b = 0.f;

    double input = 0.f;
    double output = 0.f;
    
    double feedForward(double const & x)
    {
        input = x;
        double const sigma = w*x + b;
        output = getActivation(sigma);
        
        return output;
    }

    void propBackward(double const & target)
    {
        double const alpha = 0.1f; // learning rate
        double const grad = (output - target) * getActGrad(output);
        
        w -= alpha*grad*input; // last input came from d(wx+b)/dw = x
        b -= alpha*grad*1.0f; // last 1.0f came from d(x+b)/db = 1.0f
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

        assert(false);
    }

    double getActGrad(double  const & x)
    {
        switch(activationType)
        {
            case ActivationType::Identity:
            {
                return 1.0f;
            }
            break;
            case ActivationType::ReLU:
            {
                if (x>0)
                {
                    return 1.0f;
                }
                else
                {
                    return 0.0f;
                }
            }
            break;
        }
        assert(false);
    }
};

int main()
{
    Neuron neuron;
    neuron.w = 2.0f;
    neuron.b = 1.0f;
    
    for(int i = 0 ; i < 100; i++)
    {
        std::cout << "Training " << i << std::endl;
        std::cout << "Input = 1.0 " << neuron.feedForward(1.0) << std::endl;
        neuron.propBackward(4.0f);
        std::cout << " W = " << neuron.w << " B = " << neuron.b << std::endl;
    }
    return 0;
}