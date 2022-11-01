use std::cell::RefCell;
use std::rc::Rc;
use std::ops::Sub;


// Definition for a binary tree node.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Rc<RefCell<ListNode>>>
}

impl ListNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    ListNode {
      val,
      next: None,
    }
  }
}

type Node = Option<Rc<RefCell<ListNode>>>;

pub struct Solution();
impl Solution {
    pub fn get_intersection_node(head_a: Node, head_b: Node) -> Node {
        let (mut len_a, mut len_b) = (0i32, 0i32);

        let mut cur_a = head_a.clone();
        while cur_a.is_some() {
            cur_a = cur_a.unwrap().borrow().next.clone();
            len_a += 1;
        }
        
        let mut cur_b = head_b.clone();
        while cur_b.is_some() {
            cur_b = cur_b.unwrap().borrow().next.clone();
            len_b += 1;
        }

        let (mut cur_a, mut cur_b) = (head_a.clone(), head_b.clone());
        let diff = len_a.sub(len_b).abs();
        if len_a < len_b {
            for _ in 0..diff {
                cur_b = cur_b.unwrap().borrow().next.clone();
            }
        }

        if len_a > len_b {
            for _ in 0..diff {
                cur_a = cur_a.unwrap().borrow().next.clone();
            }
        }

        while cur_a.is_some() && cur_b.is_some() {
            if Rc::ptr_eq(&cur_a.as_ref().unwrap(), &cur_b.as_ref().unwrap()) {
                return Some(cur_a.unwrap().clone());
            }

            cur_a = cur_a.unwrap().borrow().next.clone();
            cur_b = cur_b.unwrap().borrow().next.clone();
        }

        None
    }
}

fn main() {
    let mut head_a = ListNode::new(4);
    let mut a_1 = ListNode::new(1);

    let mut head_b = ListNode::new(5);
    let mut b_1 = ListNode::new(6);
    let mut b_2 = ListNode::new(1);

    let mut node_8 = ListNode::new(8);
    let mut node_4 = ListNode::new(4);
    let mut node_5 = ListNode::new(5);

    node_4.next = Some(Rc::new(RefCell::new(node_5)));
    node_8.next = Some(Rc::new(RefCell::new(node_4)));

    let node_8_ref = Rc::new(RefCell::new(node_8));

    a_1.next = Some(node_8_ref.clone());
    b_2.next = Some(node_8_ref.clone());

    head_a.next = Some(Rc::new(RefCell::new(a_1)));
    b_1.next = Some(Rc::new(RefCell::new(b_2)));
    head_b.next = Some(Rc::new(RefCell::new(b_1)));

    let mut head_a = Some(Rc::new(RefCell::new(head_a)));
    let mut head_b = Some(Rc::new(RefCell::new(head_b)));

    println!("A: {head_a:?}");
    println!("B: {head_b:?}");
    println!("intersection: {:?}", Solution::get_intersection_node(head_a, head_b));
}