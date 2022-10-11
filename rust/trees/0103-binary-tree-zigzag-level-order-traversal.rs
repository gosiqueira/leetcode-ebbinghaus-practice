// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
impl Solution {
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {return vec![]};

        let mut levels = vec![];
        let mut to_visit = VecDeque::from([root.unwrap()]);
        while !to_visit.is_empty() {
            let mut level = vec![];
            let mut is_zig = levels.len()%2 == 0;
            if is_zig { // left to right level traversal
                for _ in 0..to_visit.len() {
                    let node = to_visit.pop_front().unwrap();
                    let node = node.borrow();

                    level.push(node.val);
                    for child in [node.left.clone(), node.right.clone()] {
                        if child.is_none() {continue};

                        to_visit.push_back(child.unwrap());
                    }
                }
            } else { // right to left level traversal
                for _ in 0..to_visit.len() {
                    let node = to_visit.pop_back().unwrap();
                    let node = node.borrow();

                    level.push(node.val);
                    for child in [node.right.clone(), node.left.clone()] {
                        if child.is_none() {continue};

                        to_visit.push_front(child.unwrap());
                    }
                }
            }

            levels.push(level);
        }

        levels
    }
}