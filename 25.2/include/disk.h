#pragma once

void disk()
{
    std::fstream file("/Users/german/Desktop/Skillbox/25.2/data.txt", std::ios::out | std::ios::in);
    cout << "Enter the command (1 - save / 2 - load): ";
    int comm;
    cin >> comm;

    if (!file.is_open())
    {
        cout << "File error!";
        exit(EXIT_FAILURE);
    }

        if (comm == 1) 
        {
            for (int i = 0; i < 8; ++i)
                file << data[i] << " ";   
        }  
        else if (comm == 2)
        {
            int x;
            for (int i = 0; i < 8; ++i)
            {
                file >> x;
                data[i] = x;
            }
        }
    file.close();
}