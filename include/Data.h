class Data
{
    //ʵ������
    type data[global::data_amount];

public:
    //�±����
    const type &operator[](Index index)
    {
        //��������index==data_amount,��ΪvectorҪ��β�������
        if (index <= global::data_amount)
        {
            Draw(index);
            return data[index];
        }
        else
            global::overflow(index, __func__);
        return data[0];
    }
    //��װ��data[index_1]=data[index_2];
    void Set(Index index_1, Index index_2)
    {
        if (
            index_1 < global::data_amount &&
            index_2 < global::data_amount)
        {
            data[index_1] = data[index_2];
            Draw(index_1);
            Draw(index_2);
        }
        else
            global::overflow(
                index_1 >= global::data_amount ? index_1 : index_2, __func__);
    }
    //��װ��data[index]=value;
    void Set(Index index, type value)
    {
        if (index < global::data_amount)
        {
            data[index] = value;
            Draw(index);
        }
        else
            global::overflow(index, __func__);
    }
    //��������
    void swap(Index index_1, Index index_2);
    //������
    void mix();
    //����������
    void Draw();
    //����������
    void Draw(Index index);
    //���캯��
    Data();
};