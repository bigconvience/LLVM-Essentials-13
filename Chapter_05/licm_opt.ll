; ModuleID = 'licm.bc'
source_filename = "licm.ll"

define void @func(i32 %i) {
Entry:
  %loopinvar = mul i32 %i, 17
  br label %Loop

Loop:                                             ; preds = %Loop, %Entry
  %j = phi i32 [ 0, %Entry ], [ %Val, %Loop ]
  %Val = add i32 %j, %loopinvar
  %cond = icmp eq i32 %Val, 0
  br i1 %cond, label %Exit, label %Loop

Exit:                                             ; preds = %Loop
  ret void
}
