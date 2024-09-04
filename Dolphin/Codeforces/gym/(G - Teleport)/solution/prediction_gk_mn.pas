{$Q+,R+}

uses
    math;

const
    MAX_N = 500000;
    MAX_M = 500000;
var
    n, m, i, c: longint;
    a: array [1..MAX_N] of longint;
    b: array [1..MAX_M] of boolean;
    q: array [-MAX_N..MAX_N] of longint;
    total: int64;
    sum, p: longint;
    mn, mx: longint;
begin
    assign(input, 'prediction.in'); reset(input);
    assign(output, 'prediction.out'); rewrite(output);

    read(n, m);
    for i := 1 to n do begin
        read(a[i]);
        b[a[i]] := true;
    end;

    total := 0;
    fillchar(q, sizeof(q), 0);

    for c := 1 to m do begin
        if b[c] then begin
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
    writeln(total);
end.
