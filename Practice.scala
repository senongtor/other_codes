//Tree operations and case classes
abstract class Tree[+T]
case class Node[T](label: T, left: Tree[T], right: Tree[T]) extends Tree[T]{
	override def toString()="Node("+label+left+right+")"
}
case class Leaf[T](label: T) extends Tree[T]{
	override def toString()="Leaf("+label+")"
} 

abstract class OTree[T <: Ordered[T]]
case class ONode[T <: Ordered[T]](v:T, l:OTree[T], r:OTree[T]) extends OTree[T]
case class OLeaf[T <: Ordered[T]](v:T) extends OTree[T]

case class O(n:Int) extends Ordered[O] {
	def compare(that: O) =  this.n - that.n
	override def toString()="MAX:"+n.toString()
}

trait Addable[T]{
	def +(x:T):T
}

class A(x:Int) extends Addable[A]{
	var value=x;
	override def +(a:A)=new A(value+a.value)
	override def toString()="A("+value+")"
} 

class B(x:Int) extends A(x){
	value=x;
	override def toString()="B("+value+")"
}
class C(x:Int) extends B(x){
	value=x;
	override def toString()="C("+value+")"
}

object Practice{
	def inOrder[T](tree:Tree[T]):List[T]=tree match{
        case Node(label, left, right) => inOrder(left) ::: List(label) ::: inOrder(right) //put the label at mid
        case Leaf(label) => List(label)
	} 
	def treeSum[T<:Addable[T]](tree:Tree[T]):T=tree match{
		case Node(label, left, right) => treeSum[T](left)+label+treeSum[T](right)
		case Leaf(label)=>label
	}
	def treeMap[T,V](f:T=>V,tree:Tree[T]):Tree[V]=tree match{
		case Leaf(label)=>Leaf(f(label))
		case Node(label,left,right)=>Node(f(label), treeMap(f,left),treeMap(f,right))
	}
	def BTreeMap(f:B=>B,tree:Tree[B]):Tree[B]=treeMap[B,B](f,tree)
		
def test() {
    def faa(a:A):A = new A(a.value+10)
    def fab(a:A):B = new B(a.value+20)
    def fba(b:B):A = new A(b.value+30)
    def fbb(b:B):B = new B(b.value+40)
    def fbc(b:B):C = new C(b.value+50)
    def fcb(c:C):B = new B(c.value+60)
    def fcc(c:C):C = new C(c.value+70)
    def fac(a:A):C = new C(a.value+80)
    def fca(c:C):A = new A(c.value+90)
 
    val myBTree: Tree[B] = Node(new B(4),Node(new B(2),Leaf(new B(1)),Leaf(new B(3))),
 		               Node(new B(6), Leaf(new B(5)), Leaf(new B(7))))
 
    val myATree: Tree[A] = myBTree //A Tree expecting type A can intake type B since Tree is covariant typed
 
    println("inOrder = " + inOrder(myATree))
    println("Sum = " + treeSum(myATree))
	//Function subtyping
	
	
    // println(BTreeMap(faa,myBTree))
    // We are passing A=>A to BTreeMap who takes B=>B
    // and althoug A>:B, the returning conflict the covariance
    println(BTreeMap(fab,myBTree))
    //println(BTreeMap(fba,myBTree))
	//We are passing B=>A to BTreeMap who takes B=>B
	//and since A>:B, the returning conflict the covariance
    println(BTreeMap(fbb,myBTree))
    println(BTreeMap(fbc,myBTree))
    //println(BTreeMap(fcb,myBTree))
	//We are passing C=>B to BTreeMap who takes B=>B
	//and C:<B so input conflict the contravariance
    //println(BTreeMap(fcc,myBTree))
	//We are passing C=>C to BTreeMap who takes B=>B
	//and although C:<B but the input conflict the contravariance
    println(BTreeMap(fac,myBTree))
    //println(BTreeMap(fca,myBTree))
	//We are passing C=>A to BTreeMap who takes B=>B
	//and C:<B, B<:A so covariance and contravariance are conflicted
    println(treeMap(faa,myATree))
    println(treeMap(fab,myATree))
//     println(treeMap(fba,myATree))
//     We are passing B=>A to treeMap who takes A=>A
//     and B:<A so input conflict the contravariance
//     println(treeMap(fbb,myATree))
//     contravariance not reserved on the input side
//     since B<:A but covariance is reserved since B<:A
//     println(treeMap(fbc,myATree))
//     contravariance not reserved on the input side
//     since B<:A but but covariance is reserved since C<:A
//     println(treeMap(fcb,myATree))
//     contravariance not reserved on the input side
//     since C<:A but covariance is reserved since B<:A
//     println(treeMap(fcc,myATree))
//     contravariance not reserved on the input side
//     since C<:A but covariance is reserved since C<:A
    println(treeMap(fac,myATree))
//     println(treeMap(fca,myATree))
//     contravariance not reserved on the input side
//     since C<:A
 }
def max[T <: Ordered[T]](a:T,b:T,c:T):T={
	
  if (a.compare(b)<0){
    if (b.compare(c)<0){
    	return c
    }
 	else {return b}
    }
	
  else{
	if (c.compare(a)<0){
    	return a
    }
 
	else {c}
   }
}

def maxlabel[T <: Ordered[T]](tree:OTree[T]):T=tree match{
	case ONode(v,l:OTree[T],r:OTree[T])=> max(v,maxlabel[T](l),maxlabel[T](r))
	case OLeaf(v)=> v
}
 
  def main(args: Array[String]){
	  test();
	val _oTree: OTree[O] = ONode(new O(4),ONode(new O(2),OLeaf(new O(1)),OLeaf(new O(3))),  		               
  							ONode(new O(6), OLeaf(new O(9)), OLeaf(new O(7))))   
	println(maxlabel(_oTree))	
  }
}
