class Data;

//ȫ����
class global
{
public:
    //���ھ��
    static HWND hWnd;

    //��ͼ���
    static HDC hdc;

    //��ɫ��ˢ
    static HBRUSH redBrush;

    //ʵ������
    static Data *data;

    //ÿ�β�������ʱ
    static DWORD delayTime;

    //���������Ϣ
    static ofstream out;
    static void overflow(Index index,const char* sourse)
    {
        out << "error:overflow at " << index << " form " << sourse <<endl;
        PostMessage(hWnd,WM_DESTROY,0,0);
    }

    //��������,���������޸�
    static const Index data_amount = 256;

    //������������Ļ�ϵĿ��
    static const DWORD unitWeight = 4;

    //ÿ���������ݵĲ�
    static const DWORD unitHeight = 2;

    //���ڳ�ʼλ��
    static const DWORD win_x = 100;
    static const DWORD win_y = 50;

    //���ڵĸ߶ȺͿ��,��unitHeight��data_amount�������
    static const DWORD height = data_amount * unitHeight;
    static const DWORD weight = data_amount * unitWeight;

    //��Ե����
    static const DWORD blank = 50;
};