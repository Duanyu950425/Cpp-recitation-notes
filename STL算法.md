## STL（标准模板库） ##
### 1.STL的重要特点：数据结构与算法的分离。
 ###
### 2.容器 ###
	
1) 序列式容器（Sequence containers）：vector、deque、list 

每个元素都有固定位置－－取决于插入时机和地点，和元素值无关。

2) 关联式容器（Associated containers）：set、multiset、map、multimap
			
元素位置取决于特定的排序准则，和插入顺序无关。 
  ![](https://i.imgur.com/cwYzloZ.png)

|数据结构  |描述   |实现头文件|
|:-------:|:-----:|:--------:|
|向量（vector）|连续存储的元素|vector|
|链表(list)|由节点组成的双向链表，每个结点包含着一个元素|list|
|双队列(deque)|连续存储的指向不同元素的指针所组成的数组|deque|
|集合(set)|由节点组成的红黑树，每个节点都包含着一个元素，节点之间以某种作用于元素对的谓词排列，没有两个不同的元素能够拥有相同的次序|允许存在两个次序相等的元素的集合set|
|多重集合(multiset)|允许存在两个次序相等的元素的集合|set|
|栈(stack)|后进先出的值的排列|stack|
|队列(queue)|先进先出的执的排列|queue|
|优先队列(priority_queue)|元素的次序是由作用于所存储的值对上的某种谓词决定的的一种队列|queue|
|映射(map)|由{键，值}对组成的集合，以某种作用于键对上的谓词排列|map|
|多重映射(multimap)|允许键对有相等的次序的映射|map|

### 3.算法 ###

- 常用的查找算法

1) adjacent_find()

——作用：在iterator对标识元素范围内，查找一对相邻重复元素，找到则返回指向这对元素的第一个元素的迭代器。否则返回past-the-end

——算法
   	
	vector<int> vecInt;
	vecInt.push_back(1);
	vecInt.push_back(2);
	vecInt.push_back(2);
	vecInt.push_back(4);
	vecInt.push_back(5);
	vecInt.push_back(5);
	vector<int>::iterator 
	it=adjacent_find(vecInt.begin(),vecInt.end());//*it==2

2）binary_search()

——作用：在有序序列中查找value,找到则返回true。注意：在无序序列中，不可使用。

——算法

    set<int> setInt;
    setInt.insert(3);
    setInt.insert(1);
    setInt.insert(7);
    setInt.insert(5);
    setInt.insert(9);
    
    bool bFind=binary_search(setInt.begin(),setInt.end(),5);

3）count()

——作用：利用等于操作符，把标志范围内的元素与输入值比较，返回相等的个数。

——算法

    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(2);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(2);
    vecInt.push_back(5);
    int iCount = count(vecInt.begin(),vecInt.end(),2);	//iCount==3

4）count_if()

——算法：

    //假设vector<int> vecIntA，vecIntA包含1,3,5,7,9元素
    //先定义比较函数
    bool GreaterThree(int iNum)
    {
    		if(iNum>=3)
    		{
    			return true;
    		}
    		else
    		{
    			return false;
    		}
    }
    
    int iCount = count_if(vecIntA.begin(), vecIntA.end(), GreaterThree);
    //此时iCount == 4

5）equal_range()

——作用：返回一对iterator，第一个表示lower_bound,第二个表示upper_bound。

6）find()

——作用：利用底层元素的等于操作符，对指定范围内的元素与输入值进行比较。当匹配时，结束搜索，返回该元素的迭代器。

——算法

    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(7);
    vecInt.push_back(9);
    vector<int>::iterator it = find(vecInt.begin(), vecInt.end(), 5)；//*it == 5

7）find_if()

——作用：使用输入的函数代替等于操作符执行find。返回被找到的元素的迭代器。

——算法
    
    //假设vector<int> vecIntA，vecIntA包含1,3,5,3,9元素 
    vector<int>::it=find_if(vecInt.begin(),vecInt.end(),GreaterThree);
    //此时 *it==3, *(it+1)==5, *(it+2)==3, *(it+3)==9

- 常用的排序算法

1)merge()	

——作用：合并两个有序序列，存放到另一个序列。	

——算法

    vecIntA,vecIntB,vecIntC是用vector<int>声明的容器，vecIntA已包含1,3,5,7,9元素，vecIntB已包含2,4,6,8元素
    vecIntC.resize(9);  //扩大容量
    merge(vecIntA.begin(),vecIntA.end(),vecIntB.begin(),vecIntB.end(),vecIntC.begin());
    //此时vecIntC就存放了按顺序的1,2,3,4,5,6,7,8,9九个元素

2）sort()	

——作用：以默认升序的方式重新排列指定范围内的元素。若要改排序规则，可以输入比较函数。	

——算法

    Class CStudent:
    {
    public:
    CStudent(int iID, string strName)
    		{
    			m_iID=iID;  
    			m_strName=strName; 
    		}
    public:
    	int m_iID;
    	string m_strName;
    }
    //学号比较函数
    bool Compare(const CStudent &stuA,const CStudent &stuB)
    {
     		 return (stuA.m_iID<strB.m_iID);
    }
    void main()
    {
       vector<CStudent> vecStu;
       vecStu.push_back(CStudent(2,"老二"));
       vecStu.push_back(CStudent(1,"老大"));
       vecStu.push_back(CStudent(3,"老三"));
       vecStu.push_back(CStudent(4,"老四"));
    
       sort(vecStu.begin(),vecStu.end(),Compare);
    
    //  此时，vecStu容器包含了按顺序的"老大对象","老二对象","老三对象","老四对象"
    }

3）random_shuffle()	

——作用：对指定范围内的元素随机调整次序。

——算法

	srand(time(0));	//设置随机种子
    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(7);
    vecInt.push_back(9);
    string str("itcastitcast ");
    random_shuffle(vecInt.begin(), vecInt.end()); //随机排序，结果比如：9,7,1,5,3
    random_shuffle(str.begin(), str.end());	//随机排序，结果比如：" itstcasticat "

4）reverse()		

——算法

    vector<int> vecInt;
    vecInt.push_back(1);
    vecInt.push_back(3);
    vecInt.push_back(5);
    vecInt.push_back(7);
    vecInt.push_back(9);
    
    reverse(vecInt.begin(), vecInt.end());		//{9,7,5,3,1}

- 常用的拷贝和替换算法

1）copy()	

——算法

    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(7);
    vecIntA.push_back(9);
    
    vector<int> vecIntB;
    vecIntB.resize(5);			//扩大空间
    
    copy(vecIntA.begin(), vecIntA.end(), vecIntB.begin());	//vecIntB: {1,3,5,7,9}

2）replace()

——算法

	//replace(beg,end,oldValue,newValue):将指定范围内的所有等于oldValue的元素替换成newValue。
    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(3);
    vecIntA.push_back(9);
    
    replace(vecIntA.begin(), vecIntA.end(), 3, 8);		//{1,8,5,8,9}

3）replace_if()	

——算法

    说明：
    replace_if : 将指定范围内所有操作结果为true的元素用新值替换。
    
    replace_if(vecIntA.begin(),vecIntA.end(),GreaterThree,newVal)
    其中 vecIntA是用vector<int>声明的容器
    GreaterThree 函数的原型是 bool GreaterThree(int iNum)
    
    //把大于等于3的元素替换成8
    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(3);
    vecIntA.push_back(9);
    
    replace_if(vecIntA.begin(), vecIntA.end(), GreaterThree, 8);		// GreaterThree的定义在上面。

4）swap()	

——算法

    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    		
    vector<int> vecIntB;
    vecIntB.push_back(2);
    vecIntB.push_back(4);
    
    swap(vecIntA, vecIntB);  //交换

- 常用的算术和生成算法

1）accumulate()	

——作用：对指定范围内的元素求和，然后结果再加上一个由val指定的初始值。

——算法
	    
	#include<numeric>
    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(7);
    vecIntA.push_back(9);
    int iSum = accumulate(vecIntA.begin(), vecIntA.end(), 100);		 //iSum==125
    
2）fill()	

——作用：将输入值赋给标志范围内的所有元素。	

——算法

    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(7);
    vecIntA.push_back(9);
    fill(vecIntA.begin(), vecIntA.end(), 8);		//8, 8, 8, 8, 8

- 常用的集合算法

1）set_union()	

——作用：构造一个有序序列，包含两个有序序列的并集。	

2）set_intersection()	

——作用：构造一个有序序列，包含两个有序序列的交集。	

3）set_difference()	

——作用：构造一个有序序列，该序列保留第一个有序序列中存在而第二个有序序列中不存在的元素。

——算法

    vector<int> vecIntA;
    vecIntA.push_back(1);
    vecIntA.push_back(3);
    vecIntA.push_back(5);
    vecIntA.push_back(7);
    vecIntA.push_back(9);
    //并集
    set_union(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());		
    //vecIntC : {1,3,5,6,7,8,9,0,0,0}
    //交集
    fill(vecIntC.begin(),vecIntC.end(),0);
    set_intersection(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());		
    //vecIntC: {1,3,5,0,0,0,0,0,0,0}
    
    //差集
    fill(vecIntC.begin(),vecIntC.end(),0);
    set_difference(vecIntA.begin(), vecIntA.end(), vecIntB.begin(), vecIntB.end(), vecIntC.begin());	
    		   //vecIntC:{7,9,0,0,0,0,0,0,0,0}

- 常用的遍历算法

|遍历算法|for_each()|transform()|
|:-----:|:---------:|:--------:|
|算法形式|`for_each(begin, end, func);`|`transform(b1, e1, b2, op)` `transform(b1, e1, b2, b3, op)`|
|算法使用区别|for_each所使用的函数对象，参数是引用，没有返回值 |transform所使用的函数对象，参数一般不使用引用，而是还有返回值|
|案例|`void mysquare(int &num){num = num * num;}`|`int mysquare2(int num) {return num = num * num;}`|
|优点|速度快	|速度慢|
|缺点	|不灵活	|非常灵活