{$Q+,R+}

uses
    math;

const
    MAX_N = 500000;
    MAX_M = 500000;
var
    n, m, i, j, c: longint;
    a: array [1..MAX_N] of longint;
    b: array [1..MAX_M] of longint;
    q: array [-MAX_N..MAX_N] of longint;
    total: int64;
    bound: longint;
    sum, p: longint;
    mn, mx: longint;
    z: longint;
begin
    assign(input, 'prediction.in'); reset(input);
    assign(output, 'prediction.out'); rewrite(output);

    read(n, m);
    for i := 1 to n do begin
        read(a[i]);
        inc(b[a[i]]);
    end;

    bound := round(sqrt(n));

    total := 0;
    for c := 1 to m do begin
        if b[c] >= bound then begin
            sum := 0;
            p := 0;
            mn := 0;
            mx := 0;
            q[0] := 1;
            for i := 1 to n do begin
                if a[i] = c then begin
                    inc(sum, q[p]);
                    inc(p);
                end else begin
                    dec(p);
                    dec(sum, q[p]);
                end;
                inc(q[p]);
                mn := min(mn, p);
                mx := max(mx, p);
                total := total + sum;
            end;
            for i := mn to mx do begin
                q[i] := 0;
            end;
        end;
    end;

    for i := 1 to n do begin
        z := 0;
        for j := i to min(i + 3 * bound, n) do begin
            inc(q[a[j]]);
            if z = 0 then begin
                c := a[j];
            end;
            if c = a[j] then begin
                inc(z);
            end else begin
                dec(z);
            end;
            if (b[c] < bound) and (j - i + 1 < 2 * q[c]) then begin
                total := total + 1;
            end;
        end;
        for j := i to min(i + 3 * bound, n) do begin
            dec(q[a[j]]);
        end;
    end;
    writeln(total);
end.
