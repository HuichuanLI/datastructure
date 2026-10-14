public class LinkedList<E> {

    private class Node {
        public E e;
        public Node next;

        public Node(E e, Node next) {
            this.e = e;
            this.next = next;
        }

        public Node(E e) {
            this(e, null);
        }

        public Node() {
            this(null, null);
        }

        @Override
        public String toString() {
            return e.toString();
        }
    }
        private Node dummyHead;
        private int size;

        public LinkedList(){
            dummyHead=new Node(null,null);
            size=0;
        }
        //获取链表中的元素个数
        public int getSize(){
            return size;
        }
        //返回链表是否为空
        public boolean isEmpty(){
            return size==0;
        }
        //在链表中间index(0-based)位置添加元素e
        public void add(int index,E e){
            if(index<0||index>size)throw new IllegalArgumentException("Add failed.Illegal index.");
            else{
                Node prev=dummyHead;
                for(int i=0;i<index ;i++){
                    prev=prev.next;}
                    Node node=new Node(e,prev.next);
                    prev.next=node;
                    size++;
                }
            }
        //向链表头添加元素e
        public void addFirst(E e){
    //             Node node=new Node(e);
    //             node.next=head;
    //             head=node;
            add(0,e);
    }
        //在链表尾添加元素e
        public void addLast(E e){
            add(size,e);
        }
        //获得链表第index位置的元素
        public E get(int index){
            if(index<0||index>size)throw new IllegalArgumentException("Get failed.Illegal index.");
            Node cur=dummyHead.next;
            for(int i=0;i<index;i++){
                cur=cur.next;
            }
            return cur.e;
        }
        //获得链表的第一个元素
        public E getFirst(){
            return get(0);
        }
        //获得链表的最后一个元素
        public E getLast(){
            return get(size);
        }
        //修改第index位置元素,更新为传入的e
        public void set(int index,E e){
            if(index<0||index>size)throw new IllegalArgumentException("Set failed.Illegal index.");
            Node cur=dummyHead.next;
            for(int i=0;i<index;i++){
                cur=cur.next;
            }
            cur.e=e;
        }
        //查找链表中是否有元素e
        public boolean contains(E e){
            Node cur=dummyHead.next;
//            for(int i=0;i<size;i++){
//                cur=cur.next;
//                if(cur.e.equals(e))return true;
//            }
//            return false;
            while(cur !=null) {
                if (cur.e.equals(e)) return true;
                cur=cur.next;
            }
            return false;
        }
        //删除链表index位置的元素e
        public E remove(int index){
            if(index<0||index>size)throw new IllegalArgumentException("Delete failed.Illegal index.");
            Node prev=dummyHead;
            for(int i=0;i<index;i++){
                prev=prev.next;
            }
            Node retNode=prev.next;
            prev.next=retNode.next;
            retNode.next=null;
            size--;
            return retNode.e;
        }
        //从链表中删除第一个元素，返回e
        public E removeFirst(){
            return remove(0);
        }
        //从链表中删除最后一个元素，返回e
        public E removeLast(){
            return remove(size-1 );
        }






        @Override
        public String toString(){
            StringBuilder res=new StringBuilder();
            //循环：for(cur=dummyhead.next;cur!=null;cur=cur.next);
            Node cur=dummyHead.next;
            while(cur!=null){
                res.append(cur+"->");
                cur=cur.next;
            }
            res.append("NULL");
            return res.toString();
        }



    }

