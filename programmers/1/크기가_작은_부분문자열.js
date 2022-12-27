function solution(t, p) {
  let t_l = t.length;
  let p_l = p.length;

  let tmp = [];

  var answer = 0;

  for (let i = 0; i + p_l <= t_l; i++) {
    tmp.push(t.slice(i, i + p_l));
  }

  for (let i = 0; i < tmp.length; i++) {
    let index = parseInt(tmp[i]);
    if (index <= parseInt(p)) {
      answer++;
    }
  }

  return answer;
}
