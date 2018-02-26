/** Modular Exponent **/
ll PowerMod(ll Base,ll Exp,ll Mod)
{
	ll Ans=1;
	while(Exp>0)
	{
		if(Exp&1) Ans=(Ans*Base)%Mod;
		Exp = Exp>>1LL;
		Base = (Base*Base)%Mod;
	}
	return Ans;
}
