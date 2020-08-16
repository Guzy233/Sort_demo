class Data
{
    //实际数据
    type data[global::data_amount];

public:
    //下标操作
    const type &operator[](Index index)
    {
        //这里允许index==data_amount,因为vector要求尾后迭代器
        if (index <= global::data_amount)
        {
            Draw(index);
            return data[index];
        }
        else
            global::overflow(index, __func__);
        return data[0];
    }
    //封装了data[index_1]=data[index_2];
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
    //封装了data[index]=value;
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
    //交换数据
    void swap(Index index_1, Index index_2);
    //随机混合
    void mix();
    //画所有数据
    void Draw();
    //画单个数据
    void Draw(Index index);
    //构造函数
    Data();
};