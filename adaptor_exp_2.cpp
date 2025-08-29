#include<iostream>
using namespace std;
class MediaPlay{
    public:
    virtual void play(string file,string format)=0;
};
class DefaultMediaPlayer:public MediaPlay{
    public:
    void play(string file,string format){
        cout<<file+" is playing in format "+format<<"\n";
        return ;
    }
};
class AdvanceFormat{
    string resolution;
    string file;
    string format;
    public:
    void setResolution(string r){
        this->resolution=r;
    }
    void serFileFormat(string file,string format){
        this->file=file;
        this->format=format;
    }
    string getFile(){
        return this->file;
    }
    string getFormat(){
        return this->format;
    }
    string getResolution(){
        return this->resolution;
    }
};
class AdvanceMediaPlayer{
    public:
    virtual void playAdvanceFormat(AdvanceFormat* af)=0;
};
class AVIPlayer:public AdvanceMediaPlayer{
    // AdvanceFormat* af;
    // AVIPlayer(AdvanceFormat* af){
    //     this->af=af;
    // }
    void playAdvanceFormat(AdvanceFormat* af){
        cout<<"Advance file "+af->getFile()+" playing in format "+af->getFormat()+" with resolution "+af->getResolution()<<"\n";
        return ;
    }
};
class MediaPlayerAdapter:public MediaPlay{
    AdvanceFormat* advanceformat;
    AdvanceMediaPlayer* advancemediaplayer;
    MediaPlayerAdapter(AdvanceFormat* af){
        this->advanceformat=af;
        this->advancemediaplayer=new AVIPlayer();
    }
    void play(string file,string format){
        this->advanceformat->serFileFormat(file,format);
        this->advancemediaplayer->playAdvanceFormat(advanceformat);
    }
};
class MediaPlayerImp:public MediaPlay{
    MediaPlay* mediaplayer;
    AdvanceMediaPlayer* advancemediaplayer;
    void play(string file,string format){
        if(format=="mp3"){
            mediaplayer=new DefaultMediaPlayer();
            mediaplayer->play(file,format);
        }
        else{
            AdvanceFormat* ad=new AdvanceFormat();
            ad->setResolution("1080");
            ad->serFileFormat(file,format);
            advancemediaplayer=new AVIPlayer();
            advancemediaplayer->playAdvanceFormat(ad);
        }
    }
};
int main(){
    MediaPlay* mediaplayer=new MediaPlayerImp();
    mediaplayer->play("somg.mp3","mp3");
    mediaplayer->play("somg.adv","adv");
    return 0;
}