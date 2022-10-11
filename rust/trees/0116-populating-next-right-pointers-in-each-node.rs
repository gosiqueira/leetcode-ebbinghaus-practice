// As of this publishing, Leetcode has not implemented this
// problem for rust - definitions may differ
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
  pub next: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None,
      next: None
    }
  }
}

pub struct Solution();

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn connect(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut node = root.clone();
        while node.is_some() {
            let mut cur = node.clone();
            while let Some(parent) = cur {
                let parent = parent.borrow();
                if parent.left.is_none() {break};

                let left = parent.left.clone().unwrap();
                let mut left = left.borrow_mut();
                left.next = parent.right.clone();
                if let Some(nx) = parent.next.clone() {
                    let nx = nx.borrow();
                    
                    let right = parent.right.clone().unwrap();
                    let mut right = right.borrow_mut();
                    right.next = nx.left.clone();
                }

                cur = parent.next.clone();
            }

            let n = node.unwrap();
            node = n.borrow().left.clone();
        }

        root
    }
}

fn main() {
    let mut rt = TreeNode::new(1);
    
    let mut l = TreeNode::new(2);
    let mut ll = TreeNode::new(4);
    let mut lr = TreeNode::new(5);

    let mut r = TreeNode::new(3);
    let mut rl = TreeNode::new(6);
    let mut rr = TreeNode::new(7);

    r.left = Some(Rc::new(RefCell::new(rl)));
    r.right = Some(Rc::new(RefCell::new(rr)));

    l.left = Some(Rc::new(RefCell::new(ll)));
    l.right = Some(Rc::new(RefCell::new(lr)));
    
    rt.left = Some(Rc::new(RefCell::new(l)));
    rt.right = Some(Rc::new(RefCell::new(r)));

    let rt = Some(Rc::new(RefCell::new(rt)));
    println!("{:#?}", rt.clone());
    Solution::connect(rt.clone());
    println!("{:#?}", rt.clone());
}