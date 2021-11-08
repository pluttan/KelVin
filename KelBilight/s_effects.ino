void EF(char* effect, uint32_t n, uint32_t color=0x000000){

{//! Effect NONE
    //done nothing with mas

    //* don't like:0xFFFF
    //* don't get color

    if (effect=="none"){

    };};

{//! Effect BLIGHTNESS
    //change bilghtness for pixels

    //? ▁ ▂ ▃ ▄ ▅ ▆ ▇ ██ ▇ ▆ ▅ ▄ ▃ ▂ ▁▁ ▂ ▃ ▄ ▅ ▆ ▇ ██ ▇ ▆ ▅ ▄ ▃ ▂ ▁
    //?                n             2n             3n

    //* get n like:0xFFFF
    //* don't get color

    //* don't change black pixels 

    if (effect=="blightness"){
        for(int i=0;i<r1*2+r2*2;i++){
            uint32_t px=strip.getPixelColor(i);
            colorConverter(px);
            uint16_t k=(100/n)*(i%n+1);
            if ((i/n)%2==1)k=100-k;
            if (rgb[0]!=0)rgb[0]=(rgb[0]*k)/100;
            if (rgb[1]!=0)rgb[1]=(rgb[1]*k)/100;
            if (rgb[2]!=0)rgb[2]=(rgb[2]*k)/100;
            strip.setPixelColor(i,strip.Color(rgb[0],rgb[1],rgb[2]));
        };
    };};

{//! Effect OUT
    //get black color to every kn pixel, k=[i],i:{0,1*2+r2*2}

    //? █ █ █   █ █ █    █ █ █  
    //?       n       2n       3n

    //* get n like:0xFFFF
    //* don't get color

    //* don't change black pixels 

    if (effect=="out"){
        for(int i=0;i<r1*2+r2*2;i++){
            if (i%n==0)strip.setPixelColor(i,0x000000);
        };
    };};

{//! Effect OUT_COL
    //get color to every kn pixel, k=[i],i:{0,1*2+r2*2}

    //? █ █ █ ░ █ █ █ ░░ █ █ █ ░░
    //?       n       2n       3n

    //* get n like:0xFFFF
    //* don't get color

    //* change black pixels 

    if (effect=="out_col"){
        for(int i=0;i<r1*2+r2*2;i++){
            if (i%n==0)strip.setPixelColor(i,color);
        };
    };};

{//! Effect OUT_COL_W
    //get color to every kn pixel, k=[i],i:{0,1*2+r2*2}

    //? █ █ █ ░ █ █ █ ░░ █ █ █ ░░
    //?       n       2n       3n

    //* get n like:0xFFFF
    //* get color like:0xFFFFFF

    //* don't change black pixels 

    if (effect=="out_col_w"){
        for(int i=0;i<r1*2+r2*2;i++){
            if (i%n==0){if (strip.getPixelColor(i)!=0)strip.setPixelColor(i,color);};
        };
    };};

{//! Effect STEP_OUT
    //get black color to gaps of pixels like s1--s2, 2s1--2s2, etc.

    //? █ █ █           █ █ █           █ █ █ 
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like:0xFFFFFFFF
        //* The first four numbers is s1, other is s2 
    //*don't get color

    //* don't change black pixels 

    if (effect=="step_out"){
        uint16_t s2=n%65536;
        uint16_t s1=n/65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
            }
            else{
                if (i%s1-s2==0)flag=true;
                strip.setPixelColor(i,0x000000);
            };
        };
    };};

{//! Effect STEP_OUT_INV
    //get black color to gaps of pixels like 0--s1, s2--2s1, etc.

    //?         █ █ █           █ █ █           █ █ █ 
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like:0xFFFFFFFF
        //* The first four numbers is s1, other is s2 
    //* don't get color

    //* don't change black pixels 

    if (effect=="step_out_inv"){
        uint16_t s2=n%65536;
        uint16_t s1=n/65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
                strip.setPixelColor(i,0x000000);
            }
            else{
                if (i%s1-s2==0)flag=true;
            };
        };
    };};

{//! Effect STEP_OUT_COL
    //get color to gaps of pixels like s1--s2, 2s1--2s2, etc.

    //? █ █ █   ░ ░ ░   █ █ █   ░ ░ ░   █ █ █   ░ ░ ░
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like: 0xFFFFFFFF
        //* The first four numbers is s1, the second number is s2, other is color 
    //* get color like: 0xFFFFFF

    //* change black pixels 
    if (effect=="step_out_col"){
        uint16_t s1=n/65536;
        uint16_t s2=n%65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
            }
            else{
                if (i%s1-s2==0)flag=true;
                strip.setPixelColor(i,color);
            };
        };
    };};

{//! Effect STEP_OUT_COL_INV
    //get color to gaps of pixels like 0--s1, s2--2s1, etc.

    //? ░ ░ ░   █ █ █   ░ ░ ░   █ █ █   ░ ░ ░   █ █ █
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like: 0xFFFFFFFF
        //* The first four numbers is s1, the second number is s2, other is color 
    //* get color like: 0xFFFFFF

    //* change black pixels 

    if (effect=="step_out_col_inv"){
        uint16_t s1=n/65536;
        uint16_t s2=n%65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
                strip.setPixelColor(i,color);
            }
            else{
                if (i%s1-s2==0)flag=true;
            };
        };
    };};

{//! Effect STEP_OUT_COL
    //get color to gaps of pixels like s1--s2, 2s1--2s2, etc.

    //? █ █ █   ░ ░ ░   █ █ █   ░ ░ ░   █ █ █   ░ ░ ░
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like: 0xFFFFFFFF
        //* The first four numbers is s1, the second number is s2, other is color 
    //* get color like: 0xFFFFFF

    //* change black pixels 
    if (effect=="step_out_col"){
        uint16_t s1=n/65536;
        uint16_t s2=n%65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
            }
            else{
                if (i%s1-s2==0)flag=true;
                strip.setPixelColor(i,color);
            };
        };
    };};

{//! Effect STEP_OUT_COL_INV
    //get color to gaps of pixels like 0--s1, s2--2s1, etc.

    //? ░ ░ ░   █ █ █   ░ ░ ░   █ █ █   ░ ░ ░   █ █ █
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like: 0xFFFFFFFF
        //* The first four numbers is s1, the second number is s2, other is color 
    //* get color like: 0xFFFFFF

    //* change black pixels 

    if (effect=="step_out_col_inv"){
        uint16_t s1=n/65536;
        uint16_t s2=n%65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
                strip.setPixelColor(i,color);
            }
            else{
                if (i%s1-s2==0)flag=true;
            };
        };
    };};

{//! Effect STEP_OUT_COL_W
    //get color to gaps of pixels like s1--s2, 2s1--2s2, etc.

    //? █ █ █   ░ ░ ░   █ █ █   ░ ░ ░   █ █ █   ░ ░ ░
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like: 0xFFFFFFFF
        //* The first four numbers is s1, the second number is s2, other is color 
    //* get color like: 0xFFFFFF

    //* don't change black pixels 
    if (effect=="step_out_col_w"){
        uint16_t s1=n/65536;
        uint16_t s2=n%65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
            }
            else{
                if (i%s1-s2==0)flag=true;
                if (strip.getPixelColor(i)!=0)strip.setPixelColor(i,color);
            };
        };
    };};

{//! Effect STEP_OUT_COL_INV_W
    //get color to gaps of pixels like 0--s1, s2--2s1, etc.

    //? ░ ░ ░   █ █ █   ░ ░ ░   █ █ █   ░ ░ ░   █ █ █
    //?└-----┘ └-----┘ └-----┘ └-----┘ └-----┘ └-----┘
    //?     s1      s2     2s1     2s2     3s1     3s2

    //* get n like: 0xFFFFFFFF
        //* The first four numbers is s1, the second number is s2, other is color 
    //* get color like: 0xFFFFFF

    //* don't change black pixels 

    if (effect=="step_out_col_inv_w"){
        uint16_t s1=n/65536;
        uint16_t s2=n%65536;
        bool flag=true;
        for(int i=0;i<r1*2+r2*2;i++){
            if (flag){
                if (i%s1==0)flag=false;
                if (strip.getPixelColor(i)!=0)strip.setPixelColor(i,color);
            }
            else{
                if (i%s1-s2==0)flag=true;
            };
        };
    };};

{//! Effect COLOR_REPLACE
    //replace n color to color
    
    //? ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░

    //* get n like: 0xFFFFFF
    //* get color like: 0xFFFFFF

    //* change black pixels, when n=0x000000
    
    if (effect=="color_replace"){
        for(int i=0;i<r1*2+r2*2;i++){
            if (strip.getPixelColor(i)==n)strip.setPixelColor(i,color);
        };
    };};

}