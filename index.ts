const JsiTest = require('./NativeJsiTest').default;

export async function test(): Promise<void> {
	return await JsiTest.test();
}
