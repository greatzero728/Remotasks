beginfig(1)
  n:=5;
  u:=8mm;
 	     
  fill (0,0)--(u,0)--(u,u)--(0,u)--cycle shifted (0,5u-u) withcolor .5white;
  fill (0,0)--(u,0)--(u,u)--(0,u)--cycle shifted (0,5u-2u) withcolor .5white;
  fill (0,0)--(u,0)--(u,u)--(0,u)--cycle shifted (0,5u-3u) withcolor .5white;
  fill (0,0)--(u,0)--(u,u)--(0,u)--cycle shifted (2u,5u-3u) withcolor .5white;

  for i=0 upto n:
    draw (0,i*u)--(n*u,i*u);
    draw (i*u,0)--(i*u,n*u);
  endfor;

  drawdblarrow (3.5u, 2.5u)--(3.5u,4.5u);
  drawdblarrow (2.5u, 3.5u)--(4.5u,3.5u);

  label top ( btex u etex, (3.5u,4.5u) );
  label bot ( btex d etex, (3.5u,2.5u) );
  label lft ( btex l etex, (2.5u,3.5u) );
  label rt ( btex r etex, (4.5u,3.5u) );


endfig;

end.