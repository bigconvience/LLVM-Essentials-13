define void @func(i32 %i) {
Entry:
        br label %Loop
Loop:
        %j = phi i32 [ 0, %Entry ], [ %Val, %Loop ]
        %loopinvar = mul i32 %i, 17
        %Val = add i32 %j, %loopinvar
        %cond = icmp eq i32 %Val, 0
        br i1 %cond, label %Exit, label %Loop
Exit:            
        ret void
}
