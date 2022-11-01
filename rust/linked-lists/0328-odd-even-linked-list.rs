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
    pub fn odd_even_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {return head};

        let mut even = head.as_mut().unwrap().next.take();

        let mut cur_odd = head.as_mut();
        let mut cur_even = even.as_mut();
        loop {
            let even_has_next = cur_even.as_ref().and_then(|n| n.next.as_ref()).is_some();
            if !even_has_next {break};

            let mut next_odd = cur_even.as_mut().unwrap().next.take();
            let mut next_even = next_odd.as_mut().unwrap().next.take();

            cur_odd.as_mut().unwrap().next = next_odd;
            cur_even.as_mut().unwrap().next = next_even;

            cur_odd = cur_odd.unwrap().next.as_mut();
            cur_even = cur_even.unwrap().next.as_mut();
        }
        cur_odd.as_mut().unwrap().next = even;

        head
    }
}