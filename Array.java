public class Array<E> {
    private E [] data;
    private int size;

    //构造函数，传入数组的容量capacity构造Array
    public Array(int capacity){
        data=(E[]) new Object[capacity];
        size=0;
    }
    //无参数的构造函数，默认数组容量capacity=10
    public Array(){
        this(10);
    }
    //获取数组中的元素个数
    public int getSize(){
        return size;
    }
    //获取数组的容量
    public int getCapacity(){
        return data.length;
    }
    //返回数组是否为空
    public boolean isEmpty(){
        return size==0;
    }
    //向所有元素最后添加元素
    public void addLast(E e){
        add(size,e);
    }
    //向所有元素头添加元素
    public void addFirst(E e){
        add(0,e);
    }

    //向指定的位置添加元素
    public void add(int index,E e){
        if(index<0 || index>size)
            throw new IllegalArgumentException("Add failed.Require index>=0 and index<=size.");
        if(size==data.length)
            resize(2* data.length);
        for(int i=size-1;i>=index;i--){//记得是从后面开始移动,避免覆盖
            data[i+1]=data[i];
        }
        data[index]=e;
        size++;
    }
    //获取数组中指定index位置的元素
    E get(int index){
        if(index<0 || index>=size)
            throw new IllegalArgumentException("Get failed.Index is illegal.");
        return data[index];
    }
    E getLast(){
        return get(size-1);//避免size=0，用get判断
    }
    E getFirst(){
        return get(0);
    }
    //查找数组中是否存在e
    public boolean contains(E e){
        for(int i=0;i<size;i++){
            if(data[i].equals(e))
                return true;
        }
        return false;
    }
    //返回e对应的索引,如果不存在，返回-1
    public int find(E e) {
        for (int i = 0; i < size; i++) {
            if (data[i].equals(e))
                return i;
        }
        return -1;
    }
    //将数组index位置的元素改变成e
    void set(int index,E e){
        if(index<0 || index>=size)
            throw new IllegalArgumentException("Get failed.Index is illegal.");
        data[index]=e;
    }
    //删除索引为index的元素,返回删除的元素
    public E remove(int index){
        if(index<0 || index>=size)
            throw new IllegalArgumentException("Get failed.Index is illegal.");
        E ret=data[index];
        for(int i=index+1;i<size;i++){
            data[i-1]=data[i];
        }
        size--;
        data[size]=null;//loitering objects !=memory leak
        if(size==data.length/4 && data.length/2!=0)
            resize(data.length/2);
        return ret;
    }
    //删除第一个元素，返回
    public E removeFirst(){
        return remove(0);
    }
    //删除最后元素，返回
    public E removeLast(){
        return remove(size-1);
    }
    //从数组中删除元素e（不一定存在）
    public boolean removeElement(E e){
        int index=find(e);
        if(index!=-1){
            remove(index);
            return true;
        }
        return false;
    }
    @Override
    public String toString(){//自己定义打印输出方式
        StringBuilder res=new StringBuilder();
        res.append(String.format("Array:size=%d,capacity=%d\n",size,data.length));
        res.append('[');
        for(int i=0;i<size;i++){
            res.append(data[i]);
            if(i!= size-1)
                res.append(", ");
        }
        res.append(']');
        return res.toString();
    }

    public void removeE(int i) {
    }
    private void resize(int newCapacity){
        E[] newData =(E[])new Object[newCapacity];
        for(int i=0;i<size;i++){
            newData[i]=data[i];
            data=newData;
        }
    }
}
