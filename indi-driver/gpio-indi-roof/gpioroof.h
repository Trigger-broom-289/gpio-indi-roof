#include <indidome.h>
#include <math.h>
#include <sys/time.h>


class GpioRoof : public INDI::Dome
{
    public:
        GpioRoof();
        virtual ~GpioRoof();

        virtual bool initProperties();
        const char *getDefaultName();
        bool updateProperties();
        virtual bool ISSnoopDevice (XMLEle *root);
	virtual bool ISNewSwitch (const char *dev, const char *name, ISState *states, char *names[], int n);
	virtual bool saveConfigItems(FILE *fp);

      protected:

        bool Connect();
        bool Disconnect();
        bool isTelescopeParked();

        void TimerHit();

        virtual IPState Move(DomeDirection dir, DomeMotionCommand operation);
        virtual IPState Park();
        virtual IPState UnPark();
        virtual bool Abort();

        virtual bool getFullOpenedLimitSwitch();
        virtual bool getFullClosedLimitSwitch();
	virtual bool getHomeClosedLimitSwitch();

    private:

        IText CurrentStateT[1];
        ITextVectorProperty CurrentStateTP;

        ISState fullOpenLimitSwitch;
        ISState fullClosedLimitSwitch;
	ISState HomeClosedLimitSwitch;
        bool IsTelescopeParked;

        double MotionRequest;
        struct timeval MotionStart;
        bool SetupParms();

        float CalcTimeLeft(timeval);

};

