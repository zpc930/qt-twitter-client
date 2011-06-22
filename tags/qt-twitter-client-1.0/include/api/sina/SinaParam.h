#ifndef SINAPARAM_H
#define SINAPARAM_H

#include <string>

using namespace std;

enum sina_param_e
{
    SINA_PARAM_SOURCE,
    SINA_PARAM_ID,
    SINA_PARAM_SINCE_ID,
    SINA_PARAM_MAX_ID,
    SINA_PARAM_COUNT,
    SINA_PARAM_PAGE,
    SINA_PARAM_BASE_APP,
    SINA_PARAM_FEATURE,
    SINA_PARAM_STATUS_TEXT,
    SINA_PARAM_STATUS_RPLID,
    SINA_PARAM_MAX
};

#define SINA_PARAM_SOURCE_B     NUM_TO_BIT(SINA_PARAM_SOURCE)
#define SINA_PARAM_ID_B         NUM_TO_BIT(SINA_PARAM_ID)
#define SINA_PARAM_SINCE_ID_B   NUM_TO_BIT(SINA_PARAM_SINCE_ID)
#define SINA_PARAM_MAX_ID_B     NUM_TO_BIT(SINA_PARAM_MAX_ID)
#define SINA_PARAM_COUNT_B      NUM_TO_BIT(SINA_PARAM_COUNT)
#define SINA_PARAM_PAGE_B       NUM_TO_BIT(SINA_PARAM_PAGE)
#define SINA_PARAM_BASE_APP_B   NUM_TO_BIT(SINA_PARAM_BASE_APP)
#define SINA_PARAM_FEATURE_B    NUM_TO_BIT(SINA_PARAM_FEATURE)
#define SINA_PARAM_STATUS_TEXT  NUM_TO_BIT(SINA_PARAM_STATUS_TEXT)
#define SINA_PARAM_STATUS_RPLID NUM_TO_BIT(SINA_PARAM_STATUS_RPLID)


/*sina参数基类*/

template<typename T>
class SinaParameter
{
protected:
    string name;
    T default_value;
public:
    /*参数合法性检查*/
    virtual bool checkValidity(T value) = 0;
    virtual string convertToString(T value) = 0;
    virtual string defaultString(void) = 0;
};

/*参数cource*/
class SinaParamSource : public SinaParameter<string>
{
public:
    SinaParamSource(string appKey);
    bool checkValidity(string value);
    string convertToString(string value);
    string defaultString(void);
};

/*参数count*/
class SinaParamCount : public SinaParameter<int>
{
public:
    SinaParamCount(int default_count);
    bool checkValidity(int value);
    string convertToString(int value);
    string defaultString(void);
};

/*参数page*/
class SinaParamPage : public SinaParameter<int>
{
public:
    SinaParamPage(int default_Page);
    bool checkValidity(int value);
    string convertToString(int value);
    string defaultString(void);
};

/*参数工具类*/

class SinaParamServer
{
private:
    string getDefaultStringById(int id);
public:
    class SinaParamSource * SPSource;
    class SinaParamCount * SPCount;
    class SinaParamPage * SPPage;

    SinaParamServer(void);
    string getDefaultString(int param_bitmap);

    void setParamSource(class SinaApi * api, string value);
    void setParamCount(class SinaApi * api, int value);
    void setParamPage(class SinaApi * api, int value);
};

#endif // SINAPARAM_H
