#include <iostream>
#include <sstream>

enum switches 
{
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

int main() {

int switches_state = 0;
    
    for (int days = 1; days <= 2; ++days)
    {
        int l_t_currently = 5000, l_t_start = 5000, l_t_finish = 2700, start_light_temp = 16, end_light_temp = 20;

        for (int hours = 0; hours < 24; ++hours)
        {
            std::string buffer, movement, light_in;
            int temp_out, temp_in;
            std::cout << "Day: " << days << " " << "Hour: " << hours << std::endl;
            std::cout << "Enter the data (temperature OUT//temperature IN//movement OUT//light IN): ";
            std::getline(std::cin, buffer);
            std::stringstream buffer_stream(buffer);

            buffer_stream  >> temp_out >> temp_in >> movement >> light_in;

            if(temp_out < 0 && !(switches_state & WATER_PIPE_HEATING)){
                switches_state |= WATER_PIPE_HEATING;
                std::cout << "WATER_PIPE_HEATING / on" << std::endl;
            } 
            else if (temp_out > 5 && (switches_state & WATER_PIPE_HEATING)) {
                switches_state &= ~WATER_PIPE_HEATING;
                std::cout << "WATER_PIPE_HEATING / off" << std::endl;
            }
            
            if ((hours > 16 || hours < 5)  && (movement == "Yes") && !(switches_state & LIGHTS_OUTSIDE)){
                switches_state |= LIGHTS_OUTSIDE;
                std::cout << "LIGHTS_OUTSIDE / on" << std::endl;
            }else if (hours <= 16 && hours >= 5 && (movement == "No") && (switches_state & LIGHTS_OUTSIDE)) {
                switches_state &= ~LIGHTS_OUTSIDE;
                std::cout << "LIGHTS_OUTSIDE / off" << std::endl;
            }
            if (temp_in < 22 && !(switches_state & HEATERS))
            {
                switches_state |= HEATERS;
                std::cout << "HEATERS / on" << std::endl;
            }else if (temp_in >= 25 && (switches_state & HEATERS))
            {
                switches_state &= ~HEATERS;
                std::cout << "HEATERS / off" << std::endl;
            }
            if (temp_in >= 30 && !(switches_state & CONDITIONER))
            {
                switches_state |= CONDITIONER;
                std::cout << "CONDITIONER / on" << std::endl;

            }else if (temp_in <= 25 && (switches_state & CONDITIONER))
            {
                switches_state &= ~CONDITIONER;
                std::cout << "CONDITIONER / off" << std::endl;
            }

            if ((light_in == "on") && !(switches_state & LIGHTS_INSIDE))
            {
                switches_state |= LIGHTS_INSIDE;
                std::cout << "LIGHTS_INSIDE / on " <<std::endl;

            }else if ((light_in == "off") && (switches_state & LIGHTS_INSIDE))
            {
                switches_state &= ~LIGHTS_INSIDE;
                std::cout << "LIGHTS_INSIDE / off" << std::endl;
            }
            if ((switches_state & LIGHTS_INSIDE) && (hours >= start_light_temp && hours <= end_light_temp))      
            {
               std::cout << "Light_temp: " << l_t_currently << "K" << std::endl;
               l_t_currently -= (l_t_start - l_t_finish) / (end_light_temp - start_light_temp);
               
            }
       }   
    }
}