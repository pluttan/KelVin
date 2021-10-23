void print_pix(//Are you ready to pull some colour in your black&white live?

    char *prow,

   //how to display: 

   //  drawing starts with "s" in a circle, so by default all 4 walls
   //  are drawn in turn. For example if you write "sf" drawning will
   //  write firstly on wall s then it draw black color on wall r, 
   //  after it draw pixels on wall f and black color on wall l. But 
   //  if you write "sf" color that was drawn on wall s will draw on
   //  wall f and color that was drawn on wall f will draw on wall s

    int *mas// array of pixels that will be drawn on walls in prow
 ){
    int length_prow = sizeof(prow);
    int length_mas = sizeof(mas);

    int no_pix=0;

    strip.clear();

    for (int prow_no = 0; prow_no < length_prow; prow_no++)
    {
        char ch=prow[prow_no];
        if (ch=='s'){
            for (int pix = 0; pix < r2; pix++)
            {
                strip.setPixelColor(pix, mas[no_pix]);
                no_pix++;
            };  
        };
        if (ch=='r'){
            for (int pix = 0; pix < r1; pix++)
            {
                strip.setPixelColor(pix, mas[no_pix]);
                no_pix++;
            };  
        };
        if (ch=='f'){
            for (int pix = 0; pix < r2; pix++)
            {
                strip.setPixelColor(pix, mas[no_pix]);
                no_pix++;
            };
        };
        if (ch=='l'){
            for (int pix = 0; pix < r1; pix++)
            {
                strip.setPixelColor(pix, mas[no_pix]);
                no_pix++;
            };  
        };
    };

    strip.show();
    
}