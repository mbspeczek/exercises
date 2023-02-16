//////////////
//
// Standard DIB(BITMAPINFOHEADER) bmp to asci app.
//
//////////////
#include <iostream>
#include <fstream>
#include <vector>

int main(){

    std::string path;

    std::cout<<"path to .bmp file: ";
    std::cin>>path;

    std::ifstream readFile(path.c_str(), std::ios::binary);

    std::vector<unsigned char> file((std::istreambuf_iterator<char>(readFile)),std::istreambuf_iterator<char>());

    readFile.close();

    std::cout<<file.size()<<std::endl;

    int sizebmp;
    int pixelTableOfset;
    int bitsPerPixel;
    int imgHeight, imgWidth, imgSize;
    
    std::copy(file.begin()+2, file.begin()+6, reinterpret_cast<char*>(&sizebmp));
    std::copy(file.begin()+10, file.begin()+14, reinterpret_cast<char*>(&pixelTableOfset));
    std::copy(file.begin()+18, file.begin()+22, reinterpret_cast<char*>(&imgWidth));
    std::copy(file.begin()+22, file.begin()+26, reinterpret_cast<char*>(&imgHeight));
    std::copy(file.begin()+28, file.begin()+30, reinterpret_cast<char*>(&bitsPerPixel));
    std::copy(file.begin()+34, file.begin()+38, reinterpret_cast<char*>(&imgSize));    
    
    int onePixel = bitsPerPixel/8;
    int pixels = imgHeight*imgWidth;
    
    std::cout<<"size of file"<<sizebmp<<std::endl;
    std::cout<<"ofset "<<pixelTableOfset<<std::endl;
    std::cout<<"bitsPerPixel "<<bitsPerPixel<<std::endl;
    std::cout<<"pixels "<<pixels<<std::endl;
    std::cout<<"bits for pixels: "<<pixels*onePixel<<std::endl;
    std::cout<<"width: "<<imgWidth<<std::endl;
    std::cout<<"height: "<<imgHeight<<std::endl;
    std::cout<<"imgSize: "<<imgSize<<std::endl;

    std::vector<unsigned char> asciCodes;
   
    int tmp = 0;
    int pixelCounter = 0;
    unsigned char pixelMean;
    int padding = imgWidth%4;
    unsigned int endID = (imgHeight*imgWidth*onePixel);
   
    for(unsigned int i=0, j=0; i<endID;i++,j++){
        if(j==imgWidth*onePixel){
            i+=padding;
            j=0;
            endID+=padding;
        }
        tmp+=file.at(pixelTableOfset+i);
        pixelCounter++;

        if(pixelCounter>=onePixel){
            pixelCounter = 0;
            pixelMean = (tmp/onePixel);
            tmp=0;
            asciCodes.push_back(pixelMean);
        }
    }

    
    std::cout<<"asciCodes: "<<asciCodes.size()<<std::endl;
    unsigned char density[] = "Ñ@#W$9876543210?!abc;:+=-,._                                      ";
    int asciCode=0;
    
    std::cout<<" ------------------------------------------------------------------------ "<<std::endl;
    
    for(unsigned int i =(imgHeight-1); i>0;i--){
        for(unsigned int j=0; j<(imgWidth-1) ;j++){
            asciCode = ((asciCodes.at((i*imgWidth)+j)/255.0)*10)*5;
            std::cout<<density[asciCode];
        }
        std::cout<<std::endl;
    }
    std::cout<<" ------------------------------------------------------------------------ "<<std::endl;
        
    return 0;
}