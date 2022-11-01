// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut stack = vec![];
        let (mut slow, mut fast) = (head.as_ref(), head.as_ref());
        while fast.is_some() && fast.unwrap().next.is_some() {
            stack.push(slow.unwrap().val);
            slow = slow.unwrap().next.as_ref();
            fast = fast.unwrap().next.as_ref().unwrap().next.as_ref();
        }

        if fast.is_some() {
            slow = slow.unwrap().next.as_ref();
        }

        while slow.is_some() {
            let top = stack.pop().unwrap();
            let val = slow.unwrap().val;
            if top != val {return false};

            slow = slow.unwrap().next.as_ref();
        }

        true
    }
}