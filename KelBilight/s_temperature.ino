uint32_t* TP_temperature(uint32_t *mas, int temperature){
    int k=round(temperature/14);
    if (temperature<3150){for (int i = 0; i < r1*2+r2*2; i++)mas[i]=mas[i]-4097*k;}
    else{for (int i = 0; i < r1*2+r2*2; i++)mas[i]=mas[i]-1048576*k;};
    return mas;
};